/*  ArduSensor Shield - RGB

QColor Demo with the ArduSensor Shield.  This demonstrates one of the many uses for the
RGB LED, changing the color with an ArduSensor.

The parts from Qtechknow that you will need are:
Any Kind of ArduSensor 
ArduSensor Shield

created 23 May 12
by Quin (Qtechknow)
*/

int redPin = 6;
int greenPin = 9;
int bluePin = 10;
int potPin = A0;
int val = 0;

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    //Read the potentiometer (color wheel).
    val = analogRead(potPin);
    Serial.println(val);
    
    //Red-orange-yellow-green spectrum
    if ( val <= 341 )
    {
        //We now know the val is between 0 and 341.
        //Map the val to 0-255 for the LED.
        val = map(val, 0, 341, 0, 255);
        
        //Higher val turns red down.
        //Lower val turns red up (common anode).
        analogWrite(redPin, val);
        
        //Write the complimentary amount to the green pin.
        //The mixed color values add up to 255.
        //This keeps the LED at constant brightness.
        analogWrite(greenPin, 255-val);
        
        //Turn blue pin off.
        analogWrite(bluePin, 255);
    }
    
    //Green-teal-blue spectrum
    else if ( val <= 683 )
    {
        //We now know the val is between 341 and 683.
        //Map the val to 0-255 for the LED.
        val = map(val, 341, 683, 0, 255);
        
        //Higher val turns green down.
        //Lower val turns green up (common anode).
        analogWrite(greenPin, val);
        
        //Write the complimentary amount to the blue pin.
        //The mixed color values add up to 255.
        //This keeps the LED at constant brightness.
        analogWrite(bluePin, 255-val);
        
        //Turn red pin off.
        analogWrite(redPin, 255);
    }
    
    //Blue-indigo-purple-red spectrum.
    else
    {
        //We now know the val is between 683 and 1023.
        //Map the val to 0-255 for the LED.
        val = map(val, 683, 1023, 0, 255);
        
        //Higher val turns blue down.
        //Lower val turns blue up (common anode).
        analogWrite(bluePin, val);

        //Write the complimentary amount to the red pin.
        //The mixed color values add up to 255.
        //This keeps the LED at constant brightness.
        analogWrite(redPin, 255-val);

        //Turn green pin off.
        analogWrite(greenPin, 255);
    }
    
    //Sampling rate.
    delay(20);
}

