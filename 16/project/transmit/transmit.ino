#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Time.h>

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

RF24 radio(15,16); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
char gameState = 's';
char gameStateStr[3] = ".", carStateStrs[2][5] = {"...", "..."};
time_t gameStartTime = 0, carTimes[2];

void setup() {
  for (int i=0; i<2; i++) {
    carStateStrs[i][0] = '0' + i;
  }
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
  setTime(0);
}

void loop() {

  radio.stopListening();                                    // First, stop listening so we can talk.
  
  Serial.println(F("Now sending state to car 2"));

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

  Serial.print(gameStateStr);
  Serial.print(" - ");
  Serial.print(minute(now()));
  Serial.print(":");
  Serial.print(second(now()));
  Serial.print(" (Started "), 
  Serial.print(minute(gameStartTime));
  Serial.print(":");
  Serial.print(second(gameStartTime));
  Serial.println(")");

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
    carStateStrs[car_n][2] = msg_from_car[2];
    carTimes[car_n] = now();
  }

  if (gameState == READY_STATE) {
    if (CAR_READY(0) /*&& CAR_READY(1) */) {
      gameState = GAME_MODE;
      gameStartTime = now();
    }
  }

  if (gameState == GAME_MODE) {
    if (CAR_WON(0) /*|| CAR_WON(1)*/) {
      gameState = OVER_STATE;
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
