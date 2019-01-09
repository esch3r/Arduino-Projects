#define IrAvoid 9

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println(digitalRead(iR));
  delay(500);
}
