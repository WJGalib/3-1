#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

#define START 's'
#define READY_STATE 'r'
#define FREE_MODE 'f'
#define GAME_MODE 'g'
#define OVER_STATE 'o'

#define LOCKED 'L'
#define FREE 'F'
#define OVER 'O'
#define READY 'R'
#define GAME 'G'
#define START_SEEN 'S'
#define MID_SEEN 'M'
#define END_SEEN 'E'

#define TOTAL_ROUNDS '2'

#define FREE_BUTTON_PIN 6
#define GAME_BUTTON_PIN 7
#define RESET_BUTTON_PIN 8
#define BUZZER_PIN 9

#define FREE_COMMAND (digitalRead(FREE_BUTTON_PIN) == LOW)
#define GAME_COMMAND (digitalRead(GAME_BUTTON_PIN) == LOW)
#define RESET_COMMAND (digitalRead(RESET_BUTTON_PIN) == LOW)

#define RING_BUZZER digitalWrite(BUZZER_PIN, HIGH), delay(200), digitalWrite(BUZZER_PIN, LOW)

#define CAR_READY(N) (carStateStrs[N][1] == READY && carStateStrs[N][2] == '0')
#define CAR_WON(N) (carStateStrs[N][1] == END_SEEN && carStateStrs[N][2] == TOTAL_ROUNDS)

#define WELCOME_STR "Welcome to the Race!  (F) - Free Mode (G) - Game Mode"

RF24 radio(15,16); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
char gameState = 's';
int blinker_i = 0, timer_i = 0;
char gameStateStr[3] = ".", carStateStrs[2][5] = {"...", "..."}, gameDisplay[3][25];
time_t gameStartTime = 0, carTimes[2] = {0, 0};

void setup() {
  for (int i=0; i<2; i++) {
    carStateStrs[i][0] = '0' + i;
  }
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode (FREE_BUTTON_PIN, INPUT);
  pinMode (GAME_BUTTON_PIN, INPUT);
  pinMode (RESET_BUTTON_PIN, INPUT);
  pinMode (BUZZER_PIN, OUTPUT);
  digitalWrite (BUZZER_PIN, LOW);
}

void loop() {

  radio.stopListening();                                    // First, stop listening so we can talk.
  gameStateStr[0] = gameState;                             // Take the time, and send it.  This will block until complete

  unsigned long start_time = micros();      
  if (!radio.write( &gameStateStr, sizeof(gameStateStr) )) {
    Serial.println(F("failed"));
  }

  radio.startListening();                                    // Now, continue listening

  unsigned long started_waiting_at = micros();               // Set up a timeout period, get the current microseconds
  boolean timeout = false;                                   // Set up a variable to indicate if a response was received or not

  while ( ! radio.available() ) {                            // While nothing is received
    if (micros() - started_waiting_at > 200000 ) {           // If waited longer than 200ms, indicate timeout and exit while loop
      timeout = true;
      break;
    }
  }

  // lcd.setCursor(0,0);

  // Serial.print(gameStateStr);
  // // lcd.print(gameStateStr);
  // Serial.print(" - ");
  // // lcd.print(" - ");
  // Serial.print(minute(now()));
  // // lcd.print(minute(now()));
  // Serial.print(":");
  // // lcd.print(":");
  // Serial.print(second(now()));
  // // lcd.print(second(now()));
  // Serial.print(" (Started ");
  // // lcd.print(" (Start ");
  // Serial.print(minute(gameStartTime));
  // // lcd.print(minute(gameStartTime));
  // Serial.print(":");
  // // lcd.print(":");
  // Serial.print(second(gameStartTime));
  // // lcd.print(second(gameStartTime));
  // Serial.println(")");
  // lcd.print(")");

  if ( timeout ) {                                            // Describe the results
    Serial.println(F("Failed, response timed out."));
  } else {
    char msg_from_car[5];                             // Grab the response, compare, and send to debugging spew
    radio.read( &msg_from_car, sizeof(msg_from_car) );
    unsigned long end_time = micros();
    
    // Spew it
    Serial.print(F("Sent '"));
    Serial.print(gameStateStr);
    Serial.print(F("', Got response '"));
    Serial.print(msg_from_car);
    Serial.print(F("', Round-trip delay "));
    Serial.print(end_time - start_time);
    Serial.println(F(" microseconds"));

    int car_n = msg_from_car[0] - '0';
    carStateStrs[car_n][1] = msg_from_car[1];
    if (msg_from_car[2] != carStateStrs[car_n][2]) {
      carStateStrs[car_n][2] = msg_from_car[2];
      carTimes[car_n] = now();
    }
  }

  if (gameState == START) {
    lcd.setCursor(0, 0);
    blinker_i++;
    if (blinker_i < 3) lcd.print("Welcome to the Race!");
    else if (blinker_i == 3) lcd.print("                    ");
    else blinker_i = 0;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print("  (F) - Free Mode   ");
    lcd.setCursor(0, 3);
    lcd.print("  (G) - Game Mode   ");
  } else if (gameState == FREE_MODE) {
    lcd.setCursor(0, 0);
    blinker_i++;
    if (blinker_i < 3) lcd.print(" < < Free Mode > >");
    else if (blinker_i == 3) lcd.print("                    ");
    else blinker_i = 0;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print("  (G) - Game Mode   ");
    lcd.setCursor(0, 3);
    lcd.print("  (R) - Main Menu   ");
  } else if (gameState == READY_STATE) {
    lcd.setCursor(0, 0);
    if (timer_i <7) lcd.print("  Starting Game...  ");
    bool r0 = false, r1 = false;
    lcd.setCursor(0, 1);
    if (CAR_READY(0)) {
      r0 = true;
      if (timer_i <7) lcd.print("  Car-1 is ready!  ");
    } else lcd.print("Waiting for Car-1...");
    lcd.setCursor(0, 2);
    if (CAR_READY(1)) {
      r1 = true;
      if (timer_i <7) lcd.print("  Car-2 is ready!  ");
    } else lcd.print("Waiting for Car-2...");
    lcd.setCursor(0, 3);
    if (timer_i <7) lcd.print("Place on Start Line ");
    if (r0 && r1) {
      timer_i++;
      if (timer_i >= 7) {
        lcd.setCursor(0, 0);
        lcd.print("                    ");
        lcd.setCursor(0, 1);
        lcd.print("  Starting game in  ");
        lcd.setCursor(0, 3);
        lcd.print("                    ");
        lcd.setCursor(0, 2);
        if (timer_i < 15) lcd.print("     ... 3! ...     "), digitalWrite(BUZZER_PIN, HIGH);
        else if (timer_i < 16) digitalWrite(BUZZER_PIN, LOW);
        else if (timer_i < 20) lcd.print("   ..... 2! .....   "), digitalWrite(BUZZER_PIN, HIGH);
        else if (timer_i < 21) digitalWrite(BUZZER_PIN, LOW);
        else if (timer_i < 25) lcd.print(" ....... 1! ....... "), digitalWrite(BUZZER_PIN, HIGH);
        else if (timer_i < 26) digitalWrite(BUZZER_PIN, LOW);
        else {
          gameState = GAME_MODE;
          setTime(0);
          timer_i = 0;
        }
      }
    } else timer_i = 0;
  } else if (gameState == GAME_MODE) {
    snprintf(gameDisplay[0], 24, "Race running! %3d:%02d", minute()+hour()*60, second());
    int i = (carStateStrs[1][2] > carStateStrs[0][2]);
    snprintf(gameDisplay[1], 24, "Car-%1d: %c laps %3d:%02d", i+1, carStateStrs[i][2], minute(carTimes[i])+hour(carTimes[i])*60, second(carTimes[i]));
    snprintf(gameDisplay[2], 24, "Car-%1d: %c laps %3d:%02d", (!i)+1, carStateStrs[!i][2], minute(carTimes[!i])+hour(carTimes[!i])*60, second(carTimes[!i]));
    lcd.setCursor(0, 0), lcd.print(gameDisplay[0]);
    lcd.setCursor(0, 1), lcd.print(gameDisplay[1]);
    lcd.setCursor(0, 2), lcd.print(gameDisplay[2]);
    lcd.setCursor(0, 3), lcd.print(" (R) - Cancel game  ");
    bool w0 = CAR_WON(0), w1 = CAR_WON(1);
    if (w0 || w1) {
      gameState = OVER_STATE;
      lcd.setCursor(0, 0), lcd.print(" < < GAME OVER! > > ");
      lcd.setCursor(0, 1);
      if (!w0) lcd.print("Car-2 wins the Race!");
      else if (!w1) lcd.print("Car-1 wins the Race!");
      else lcd.print("     Race tied!     ");
      lcd.setCursor(0, 2), lcd.print("  (F) - Free Mode   ");
      lcd.setCursor(0, 3), lcd.print("  (G) - New Game    ");
    }
  }

  if (FREE_COMMAND) {
    if (gameState == START || gameState == OVER_STATE) {
      gameState = FREE_MODE;
      RING_BUZZER;
    }
  } 

  if (GAME_COMMAND) {
    if (gameState == START || gameState == OVER_STATE || gameState == FREE_MODE) {
      gameState = READY_STATE;
      RING_BUZZER;
    }
  } 

  if (RESET_COMMAND) {
    if (gameState == FREE_MODE || gameState == READY_STATE) {
      gameState = START;
      RING_BUZZER;
    }
  }
  // Try again 1s later
  //delay(2000);
}
