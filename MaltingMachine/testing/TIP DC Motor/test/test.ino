// Define which pin to be used to communicate with Base pin of TIP120 transistor
int TIP120pin = 12; //for this project, I pick Arduino's PMW pin 11
void setup()
{
pinMode(TIP120pin, OUTPUT); // Set pin for output to control TIP120 Base pin
//analogWrite(TIP120pin, 0); // By changing values from 0 to 255 you can control motor speed
}

void loop()
{
  digitalWrite(TIP120pin,HIGH);
  delay(2000);
  digitalWrite(TIP120pin,LOW);
  delay(2000);
}

