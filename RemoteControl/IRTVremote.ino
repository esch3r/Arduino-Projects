 int IRledPin =  13;    // LED connected to digital pin 13
 const int buttonPin = 10;
 int previousButtonState = 0;
 int buttonState = 0;

 // The setup() method runs once, when the sketch starts

 void setup()   {               
   // initialize the IR digital pin as an output:
   pinMode(IRledPin, OUTPUT);
   pinMode(buttonPin, INPUT);    

   Serial.begin(9600);
 }

 void loop()                    
 {
   buttonState = digitalRead(buttonPin);
   if(buttonState != previousButtonState){
    if(buttonState == HIGH){ //Sends the code every time the button is pressed.
      SendChannelUpCode();
    }
   }
   previousButtonState = buttonState;
 }

 // This procedure sends a 38KHz pulse to the IRledPin
 // for a certain # of microseconds. We'll use this whenever we need to send codes
 void pulseIR(long microsecs) {
   // we'll count down from the number of microseconds we are told to wait

   cli();  // this turns off any background interrupts

   while (microsecs > 0) {
     // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
   }

   sei();  // this turns them back on
 }

 void SendChannelUpCode() {
   // This is the code for the CHANNEL + for the TV COMCAST
  
   delayMicroseconds(8736);      //Time off (LEFT column)       
   pulseIR(8700);                //Time on (RIGHT column)    <-------DO NOT MIX THESE UP
   delayMicroseconds(4380);
   pulseIR(520);
   delayMicroseconds(500);
   pulseIR(580);
   delayMicroseconds(520);
   pulseIR(540);
   delayMicroseconds(1640);
   pulseIR(540);
   delayMicroseconds(540);
   pulseIR(560);
   delayMicroseconds(520);
   pulseIR(560);
   delayMicroseconds(580);
   pulseIR(500);
   delayMicroseconds(560);
   pulseIR(500);
   delayMicroseconds(580);
   pulseIR(520);
   delayMicroseconds(1660);
   pulseIR(520);
   delayMicroseconds(1620);
   pulseIR(580);
   delayMicroseconds(540);
   pulseIR(520);
   delayMicroseconds(1660);
   pulseIR(540);
   delayMicroseconds(1680);
   pulseIR(500);
   delayMicroseconds(1660);
   pulseIR(520);
   delayMicroseconds(1660);
   pulseIR(540);
   delayMicroseconds(1620);
   pulseIR(540);
   delayMicroseconds(580);
   pulseIR(520);
   delayMicroseconds(520);
   pulseIR(560);
   delayMicroseconds(500);
   pulseIR(560);
   delayMicroseconds(1660);
   pulseIR(560);
   delayMicroseconds(560);
   pulseIR(520);
   delayMicroseconds(540);
   pulseIR(520);
   delayMicroseconds(560);
   pulseIR(520);
   delayMicroseconds(580);
   pulseIR(520);
   delayMicroseconds(1620);
   pulseIR(540);
   delayMicroseconds(1680);
   pulseIR(520);
   delayMicroseconds(1660);
   pulseIR(520);
   delayMicroseconds(520);
   pulseIR(560);
   delayMicroseconds(1620);
   pulseIR(560);
   delayMicroseconds(1660);
   pulseIR(540);
   delayMicroseconds(1660);
   pulseIR(520);
   delayMicroseconds(1640);
   pulseIR(520);
   delayMicroseconds(38560);
   pulseIR(8700);
   delayMicroseconds(2160);
   pulseIR(540);
   delayMicroseconds(27464);
   pulseIR(8760);
   delayMicroseconds(2140);
   pulseIR(540);
 } 
