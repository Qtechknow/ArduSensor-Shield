/*  RGBdemo

ArduSensor Shield RGB LED Demo.  Uses pin D6 as the green pin, D5, for the blue
pin, and D3 for the red pin.  Credit for this demo goes to Quin (Qtechknow), 
and Sparkfun Electronics.

created 23 May 12
by Quin (Qtechknow)
*/

const int redPin = 3;    //Red LED Pin
const int greenPin = 6;  //Green LED Pin
const int bluePin = 5;   //Blue LED Pin

const int ArduSensorPin = 0;  // our ArduSensor is connected to A0 on the shield

void setup() {
  //no need for any code here
}

void loop() {
  int sensorValue = analogRead(ArduSensorPin);   //read the ArduSensor at A0

  int redValue = constrain(map(sensorValue, 0, 512, 255, 0),0,255); //calculate the red Value (255-0 over the range 0-512)
  int greenValue = constrain(map(sensorValue, 0, 512, 0, 255),0,255) - constrain(map(sensorValue, 512, 1023, 0, 255),0,255);  //calculate the green value (0-255 over 0-512 & 255-0 over 512-1023)
  int blueValue = constrain(map(sensorValue, 512, 1023, 0, 255),0,255); //calculate the blue value 0-255 over 512-1023

  // Display the requested color 

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
} 



