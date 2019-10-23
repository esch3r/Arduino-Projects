
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h> 

#define BNO055_SAMPLERATE_DELAY_MS (100)     // Delay between data requests
Adafruit_BNO055 bno = Adafruit_BNO055();     // Create sensor object bno based on Adafruit_BNO055 library

void setup(void){
Serial.begin(115200);              // Begin serial port communication
if(!bno.begin())                // Initialize sensor communication
{
 Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
}
delay(1000);
bno.setExtCrystalUse(true);           // Use the crystal on the development board
}

void loop(void)
{
imu::Vector<3> gravity = bno.getVector(Adafruit_BNO055::VECTOR_GRAVITY);
Serial.print("gX: ");Serial.print(gravity.x()); Serial.print("\t");
Serial.print("gY: ");Serial.print(gravity.y()); Serial.print("\t");
Serial.print("gZ: ");Serial.print(gravity.z()); Serial.print("\t");
Serial.println("");
}
