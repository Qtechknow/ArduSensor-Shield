/*
  Bar Graph
 
  ArduSensor Shield Demo using the onboard LED bar graph.  Uses pins D1, D2, 
  D4, D7, D8, D9, D10, D11, D12, and D13.  Credit goes to Quin (Qtechknow), and
  Tom Igoe (from Arduino).
 
 created 23 Mqy 12
 by Quin (Qtechknow) 
 
 http://www.qtechknow.com/

 */


// these constants won't change:
const int analogPin = A0;   // the pin that the ArduSensor is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = { 
  1, 2, 4, 7, 8, 9, 10,11, 12, 13 };   // an array of pin numbers to which LEDs are attached


void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}

void loop() {
  // read the ArduSensor:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } 
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  }
}



