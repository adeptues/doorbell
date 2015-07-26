#define BELLPIN 4
// duemillanove #define THRESHOLD 696
#define THRESHOLD 722
#define TIMEOUT 10000
#define LEDPIN 13
boolean pressed = false;
//TODO fix the circuit with pull down as we have 
//very low tolerances for thresholds

void setup() {

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

    delay(TIMEOUT);

    pressed = false;
    //maybe remove pressed
    //broadcast via xbee or i2c to raspberry pi
  }
  
  
  
}
