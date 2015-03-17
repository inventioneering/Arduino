int led = 13;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  
  for(int i = 0; i < 4; i++) {
   blinkLED();
  }
  
  delay(1000);
  
  for(int i = 0; i < 3; i++) {
    blinkLED();
   }
 
  delay(1000);
  
  for(int i = 0; i < 2; i++) {
   blinkLED();
  }
   
  delay(1000);
  
  blinkLED();
}

void blinkLED() {
  digitalWrite(led, HIGH);  
  delay(200);               
  digitalWrite(led, LOW);   
  delay(200);             
}
