#define BELLPIN 4
// Voltage threshold for the input signal
#define THRESHOLD 722
// set to 10 seconds
#define TIMEOUT 10000
#define LEDPIN 13
boolean pressed = false;
// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX
//TODO tidy the circuit up so we can get greater threshholds
void setup() {
  pinMode(LEDPIN,OUTPUT);
  XBee.begin(9600);
  Serial.begin(9600);
  pinMode(BELLPIN,INPUT);
  //pinMode(13,OUTPUT);
  //turn on the pull up resistor
  //digitalWrite(BELLPIN,LOW);
  //wait one second for arduino to discharge between read write
  //modes
  //delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  int in  = analogRead(BELLPIN);
  if(in > THRESHOLD && !pressed){
    
    
    Serial.print("Pressed");
    Serial.print(in);
    Serial.print("\n");
    //signal that were talking to the xbee
    digitalWrite(LEDPIN,HIGH);
    //write to the xbee
    XBee.write(1);
    //wait untill the chimes finished 
    delay(TIMEOUT);
    //turn the signal off
    digitalWrite(LEDPIN,LOW);
    pressed = false;
  }
  
  
  
}
