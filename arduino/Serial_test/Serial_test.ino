

void setup(){
  Serial.begin(9600);
  
  Serial.println("Serail test script");
  
}

void loop(){
  while(Serial.available() > 0){
    char input = Serial.read();
    
    switch(input){
      case 'A':
        Serial.println("Hello world");
        break;
        default:
          Serial.println("Unrecognised input");
    }
  }
}
