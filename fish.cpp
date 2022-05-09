#include <ESP32Servo.h>

Servo tail;  // create servo object to control a servo
Servo head;

//variables to store position as servos move
int posT = 20;   
int posH = 160;

void setup() {
  tail.setPeriodHertz(50); //standard 50 hz servo
  head.setPeriodHertz(50);
  tail.attach(39, 500, 2500);  
  head.attach(32, 500, 2500);
  
  StaticJsonDocument<200> doc;
  
}


void loop() {

  DeserializationError e = deserializeJson(doc, json);

  if (e){
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  String fish = doc["name"];
  int fishSpeed = doc[fish];

  
   
  //20-160 for decreased range of motion to allow fish to move
  //--cannot be stretched as far as servos can turn

  for (posT = 20; posT <= 160; posT += 1) { 
    // in steps of 1 degree
    tail.write(posT); //tell servo1 to move up by 1
    head.write(posH); //tell servo2 to move down by 1
    posH -= 1;  //separate incrementing since not in for loop header
    delay(15); //waits 15ms for the servo to reach the position
  }
  
  for (posT = 160; posT >= 20; posT -= 1) { //reverse of above
    tail.write(posT);      
    head.write(posH);
    posH += 1;
    delay(15);                   
  }

}