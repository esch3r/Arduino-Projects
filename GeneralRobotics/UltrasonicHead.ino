
#include <NewPing.h>
#include <Servo.h> // add servo library
#include <Kalman.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int pot =0;
int val;

Servo servobj; // instiate a servo object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() {
  Serial.begin(9600);
  servobj.attach(9);  // attaches the servo on pin 9 to the servo object
}



void loop() {
  val = analogRead(pot);
  Serial.println("Value of the pot is:");
  Serial.println(val);
  val = map(val,0, 1023, 0, 180); // maps the domain of values for the pot with values for the servo
  servobj.write(val); // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
  ultrasonic();
}


void ultrasonic() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
 
 
