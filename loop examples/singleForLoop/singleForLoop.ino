/*
  This is our introduction to for loops. Please reference this for more information: http://arduino.cc/en/Reference/For
  
*/

int led = 13;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  
  for(int i = 0; i < 4; i++) {
   blinkLED();
  }
  
  delay(1000);
}

void blinkLED() {
  digitalWrite(led, HIGH);  
  delay(200);               
  digitalWrite(led, LOW);   
  delay(200);             
}
