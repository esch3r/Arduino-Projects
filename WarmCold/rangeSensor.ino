//Created by Johnathan Machler 
//Date 1.10.19

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const int RED_PIN = 9;
const int BLUE_PIN = 10;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(RED_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();

   
  long color = map (cm,0,280,0,255);
  setColor(255,color);
   
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

// function to convert 5cm to color blue  200cm color
// map(x, a,b,  c,d)  [5,400] to [0,255]


void setColor(int redValue, int blueValue) {
  analogWrite(RED_PIN, redValue);
  analogWrite(BLUE_PIN, blueValue);
}
