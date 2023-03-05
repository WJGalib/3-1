#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8 ); // CE, CSN

const byte addresses[][6] = {"00001", "00002"};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
 char msg_from_A[20];

  if ( radio.available()) {
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
}
