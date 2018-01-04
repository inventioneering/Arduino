int timerLength;  // in seconds
int timerStartTime; // in milliseconds
int firstMillis;


#define buttonPin 21

void setup()
{

  pinMode(buttonPin, INPUT);
  pinMode(6,OUTPUT);


  Serial.begin(9600);

  timerLength = 10;  // seconds
  timerStartTime = millis(); // milliseconds -- start the timer

  firstMillis = millis();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == LOW) {
    digitalWrite(6,HIGH);
    resetTimer(20);
    
  } else {
    digitalWrite(6,LOW);
  }
  Serial.println(secondsLeft());
}


int secondsLeft() {
  if(((millis() - timerStartTime) <= timerLength*1000)) {
    return (timerLength*1000 - (millis()-timerStartTime))/1000;
  } else
  {
  return 0;
  }
}

int resetTimer(int timeInSeconds) {
  timerLength = timeInSeconds;
  timerStartTime = millis();
}


