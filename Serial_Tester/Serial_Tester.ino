
void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
 
}

void loop() {
  // plug into A0 and see what happens
    Serial.print(analogRead(A0));
    Serial.print("\n");
    delay(200);
 
}


