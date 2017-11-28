/*
 * 
 * Met with Chatham and we had a whiteboard party.  He explained how pulldown resistors work.  
 * Here's the setup:
 * 
 * Connect a momentary switch.  
 * 1 pin to port 22 (I'm on a Mega).  Set the pinmode to "pinmode(22,INPUT_PULLUP)" this sets the pin to be always 
 * "receiving" 5V
 * 1 pin to ground
 * 
 * We're going to "listen" on input pin for voltage to change from HIGH to LOW.
 */


void setup() {
  // put your setup code here, to run once:
  pinMode(22,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(22) == LOW) {
    digitalWrite(13,HIGH);
  }
    else {
    digitalWrite(13,LOW);
    }
  
}
