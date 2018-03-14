int in1 = 13;

void setup() {
  pinMode(in1, OUTPUT);
  //digitalWrite(in1, HIGH);
}



void loop() {
  digitalWrite(in1,HIGH);
  delay(5000);
  digitalWrite(in1, LOW);
  delay(5000);
}

