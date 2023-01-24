#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>



RF24 radio(15,16); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {


  radio.stopListening();                                    // First, stop listening so we can talk.
  
  Serial.println(F("Now sending Hello to node B"));

  char msg_to_B[20] = "Hello from node_A";                             // Take the time, and send it.  This will block until complete
  
  unsigned long start_time = micros();      
  if (!radio.write( &msg_to_B, sizeof(msg_to_B) )) {
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

  if ( timeout ) {                                            // Describe the results
    Serial.println(F("Failed, response timed out."));
  } else {
    char msg_from_B[20];                             // Grab the response, compare, and send to debugging spew
    radio.read( &msg_from_B, sizeof(msg_from_B) );
    unsigned long end_time = micros();

    // Spew it
    Serial.print(F("Sent '"));
    Serial.print(msg_to_B);
    Serial.print(F("', Got response '"));
    Serial.print(msg_from_B);
    Serial.print(F("', Round-trip delay "));
    Serial.print(end_time - start_time);
    Serial.println(F(" microseconds"));
  }

  // Try again 1s later
  //delay(2000);
}
