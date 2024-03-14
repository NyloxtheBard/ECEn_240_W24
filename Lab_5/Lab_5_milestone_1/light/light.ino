#include "Arduino.h"
#define PHOTODIODE_LIGHT_THRESHOLD 2
#define PHOTODIODE_PIN A1


void setup(){
  Serial.begin(9600);
  pinMode(PHOTODIODE_PIN, INPUT);
  
}

void loop(){
  
bool light = isLight(PHOTODIODE_PIN);
Serial.println(light);
}

float getPinVoltage(int pin) {
  
  return 5.08 * (float)analogRead(pin) / 1024;
}


bool isLight(int pin) {

  float light = getPinVoltage(pin);
  //Serial.println(light); // Use this line to test
  return (light > PHOTODIODE_LIGHT_THRESHOLD);
  
}



