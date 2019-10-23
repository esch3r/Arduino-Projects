#include <Wire.h>
#include<Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imuath.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);


void setup(void) {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 Serial.println("Orientation Sensor Test"); Serial.println(" ");

 /* Initialise the sensor */
 if (!bno.begin()) {
   /* There was a problem detecting the BNO055 ... check your connections 
    * */
  Serial.print ("Opps, no BNO055 detected... check your wiring or I2C"); 
  while(1); 
}

delay(1000); 
bno.setExtCrystalUse(true); 
}


void loop(void) {
              /* Get a new sensor event */
              sensors_event_t_event; 
              bno.getEvent(&event); 

              /* Display the floating point data */
              Serial.print("X: ");
              Serial.print(event.orentation.x, 4); 
              Serial.print("\tY: ");
              Serial.print(event.orentation.y, 4); 
              Serial.print("\tZ: ");
              Serial.print(event.orentiation.z, 4); 
              Serial.println(" ");

              delay(100);
}
