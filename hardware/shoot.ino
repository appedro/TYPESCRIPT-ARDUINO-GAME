// define global variables for analog pins.

// X values will be read from pin 0 and Y from pin 1
#include <Arduino_JSON.h>

#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y 1

#define A 2
#define B 3
#define C 4
#define D 5

 

void setup() {

 // Start serial because we will observe values at serial monitor
 for(int i=2;i<6;i++) pinMode(i, INPUT_PULLUP);
 Serial.begin(9600);

}

 

void loop() {

 // Print x axis values
 JSONVar myObject;
  if(!digitalRead(A)) myObject["btn"]="A";
  else if (!digitalRead(B)) myObject["btn"]="B";
  else if (!digitalRead(C)) myObject["btn"]="C";
  else if (!digitalRead(D)) myObject["btn"]="D";
  else myObject["btn"]="N";
  myObject["x"] = analogRead(PIN_ANALOG_X);
  myObject["y"] = analogRead(PIN_ANALOG_Y);
    Serial.println(myObject);

 delay(100);

}
