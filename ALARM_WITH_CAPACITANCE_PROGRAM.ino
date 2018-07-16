#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

/*Declaring Pins
const int buzzerPin = 5;

const int capsensPin = 7;


// Setting Buzzer mode to False
boolean buzzer_mode = false;

void setup()
{
  //The Following are our output
 
  pinMode(buzzerPin,OUTPUT);

 
  
  // Wait before starting the alarm
  delay(1000);
}

void loop()
{
  // To chech whether the capsens is detected or not
  if (digitalRead(capsens Pin)) {
    buzzer_mode = true; 
  }*/


CapacitiveSensor   cs_7_8 = CapacitiveSensor(7,8);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
const int buzzerPin = 13;
void setup()                    
{
   cs_7_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
    pinMode(buzzerPin,OUTPUT);
pinMode(13,OUTPUT);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_7_8.capacitiveSensor(30);
   
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                   // tab character for debug windown spacing
    

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\n");                    // tab character for debug windown spacing
    
   
    delay(100);                             // arbitrary delay to limit data to serial port 



 if(total1>500)
   {
     
   digitalWrite(13,HIGH);

   }
   else
   {
     digitalWrite(13,LOW);
    
   }

}
