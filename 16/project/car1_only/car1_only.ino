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
  const int motorBspeed  =6;
  

//Useful Variables
  int state;
  int vSpeed=200;     // Default speed, from 0 to 255

void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
   
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
  
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
   //Serial.println(state); 
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
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
  //If state is equal with letter 'I', car will go forward left
    else if (state == 'I') {
  digitalWrite (motorA1,LOW);
  //delay(1);
  digitalWrite(motorA2,HIGH);                       
  //delay(1);
  
  digitalWrite (motorB1,LOW);
  //delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'G', car will go forward right
    else if (state == 'G') {
  digitalWrite (motorA1,LOW);
  //delay(1);
  digitalWrite(motorA2,HIGH);                       
  //delay(1);
  
  digitalWrite (motorB1,LOW);
  //delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
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
  //If state is equal with letter 'J', car will go backward left
    else if (state == 'J') {
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
  //If state is equal with letter 'H', car will go backward right
    else if (state == 'H') {
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
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
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

     /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
 
    
}
