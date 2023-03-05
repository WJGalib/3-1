/* 
 * Project: Bluetooth Controlled Car
 * https://www.youtube.com/channel/UCJFYG8rKSO-ZoM9awuwZU2A?view_as=subscriber
 
 */
 
//L293 Connection   
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  = 6;
  

//Useful Variables
  int state;
  int vSpeed=255;     // Default speed, from 0 to 255
  int halfSpeed=127;

#include <SPI.h>
#include <MFRC522.h>
#include <nRF24L01.h>
#include <RF24.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance


RF24 radio(15, 16); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(14, OUTPUT);
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);

    radio.begin();
    radio.openWritingPipe(addresses[0]); // 00001
    radio.openReadingPipe(1, addresses[1]); // 00002
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
    delay(10);       // Optional delay. Some board do need more time after init to be ready, see Readme

    //SPI.begin();      // Init SPI bus
    mfrc522.PCD_Init();   // Init MFRC522
    delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}
 
void loop() {
  
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
   //Serial.println(state); 
   digitalWrite(14, LOW);
//  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
//    if (state == '0'){
//      vSpeed=0;}
//    else if (state == '1'){
//      vSpeed=100;}
//    else if (state == '2'){
//      vSpeed=180;}
//    else if (state == '3'){
//      vSpeed=200;}
//    else if (state == '4'){
//      vSpeed=255;}
//     
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
  digitalWrite (motorA1,LOW);
  //delay(1);
  digitalWrite(motorA2,HIGH);                       
  //delay(1);
  
  digitalWrite (motorB1,LOW);
  //delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
//  digitalWrite (motorA1,LOW);
//  //delay(1);
//  digitalWrite(motorA2,HIGH);                       
//  //delay(1);
//  
//  digitalWrite (motorB1,LOW);
//  //delay(1);
//  digitalWrite(motorB2,HIGH);
//
//  analogWrite (motorAspeed, 0);
//  analogWrite (motorBspeed, vSpeed);

  digitalWrite (motorA2,LOW);
  //delay(1);
  digitalWrite(motorA1,HIGH);                       
  //delay(1);
  
  digitalWrite (motorB2,HIGH);
  //delay(1);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, halfSpeed);
  analogWrite (motorBspeed, vSpeed); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
//  digitalWrite (motorA1,LOW);
//  //delay(1);
//  digitalWrite(motorA2,HIGH);                       
//  //delay(1);
//  
//  digitalWrite (motorB1,LOW);
//  //delay(1);
//  digitalWrite(motorB2,HIGH);
//
//  analogWrite (motorAspeed, vSpeed);
//  analogWrite (motorBspeed, 0);
 
  digitalWrite (motorA2,HIGH);
  //delay(1);
  digitalWrite(motorA1,LOW);                       
  //delay(1);
  
  digitalWrite (motorB2,LOW);
  //delay(1);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, halfSpeed);
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
  digitalWrite (motorA1,HIGH);
  //delay(1);
  digitalWrite(motorA2,LOW);                       
  //delay(1);
  
  digitalWrite (motorB1,HIGH);
  //delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') {
  digitalWrite (motorA1,HIGH);
  //delay(1);
  digitalWrite(motorA2,LOW);                       
  //delay(1);
  
  digitalWrite (motorB1,HIGH);
  //delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') {
  digitalWrite (motorA1,HIGH);
  //delay(1);
  digitalWrite(motorA2,LOW);                       
  //delay(1);
  
  digitalWrite (motorB1,HIGH);
  //delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
  digitalWrite (motorA2,LOW);
  //delay(1);
  digitalWrite(motorA1,HIGH);                       
  //delay(1);
  
  digitalWrite (motorB2,HIGH);
  //delay(1);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed); 
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
  
  digitalWrite (motorA2,HIGH);
  //delay(1);
  digitalWrite(motorA1,LOW);                       
  //delay(1);
  
  digitalWrite (motorB2,LOW);
  //delay(1);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }

     /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }


     char msg_from_A[20];
  
    if ( radio.available()) {
      Serial.println("hello");
      // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &msg_from_A, sizeof(msg_from_A) );             // Get the payload
      }
  
      radio.stopListening();                                        // First, stop listening so we can talk
  
      char msg_to_A[20] = "Hello from node_B";
      radio.write( &msg_to_A, sizeof(msg_to_A) );              // Send the final one back.
      radio.startListening();                                       // Now, resume listening so we catch the next packets.
      
      Serial.print(F("Got message '"));
      Serial.print(msg_from_A);
      Serial.print(F("', Sent response '"));
      Serial.print(msg_to_A);
      Serial.println(F("'"));
    }

//    delay(4);

    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      digitalWrite(14, LOW);
      return;
    }

  // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      digitalWrite(14, LOW);
      return;
    }
  
    // Dump debug info about the card; PICC_HaltA() is automatically called
    //digitalWrite(14, HIGH);
    if (mfrc522.uid.uidByte[1] < 0x68) Serial.println("START");
    else if (mfrc522.uid.uidByte[1] > 0xCB) Serial.println("MID");
    else Serial.println("END");
    
   
    
}
