
void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
 
}

void loop() {
  // plug into A0 and see what happens
    Serial.print(analogRead(A0));
    Serial.print("\n");
    //delay(50);
    
    // this makes the LED light up with the value from the sensor 
    // divided by 4 to map the values from 0 - 255
    analogWrite(9, analogRead(A0)/4);
    
 
}


