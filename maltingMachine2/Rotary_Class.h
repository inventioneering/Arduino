class RotaryEncoder
{
  // Data
  int outputA;      // one pin
  int outputB;      // second pin
  int buttonPin;    // milliseconds of off-time
  int counter;      // keeps track of rotary encoder count
  long encoderInterval; // keeps track of how often we update encoder

  // These maintain the current state
  int buttonState;                 
  int aState;
  int aLastState;
  unsigned long previousMillis;   // will store last time encoder was updated

  // Constructor
  public:
  RotaryEncoder(int pinA, int pinB, int bPin, long interval)
  {
   // instantate with input paramenter
   outputA = pinA;
   outputB = pinB;
   buttonPin = bPin;
   encoderInterval = interval;

   // rotary encoder hasn't turned yet
   counter = 0;

   // setup pins for rotary encoder
   // see: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
   pinMode(outputA,INPUT);
   pinMode(outputB,INPUT);
   pinMode(buttonPin, INPUT_PULLUP);
   digitalWrite(outputA, HIGH);
   digitalWrite(outputB, HIGH);
   digitalWrite(buttonPin, LOW);  

   // get button state and pinA of rotary encoder
   buttonState = digitalRead(buttonPin);
   aLastState = digitalRead(outputA);
   aState = aLastState;
   
   // start time 
   previousMillis = 0;
  }

  void Update() // check encoder
  {
    // check to see if it's time to change the rotaryencoder counter
//    unsigned long currentMillis = millis();
//
//    if(currentMillis - previousMillis >= encoderInterval)
//    {
      aState = digitalRead(outputA); // Reads the "current" state of the outputA
      
      
      // a pulse has occured
      if (aState != aLastState)
        {     
        if (digitalRead(outputB) != aState) // clockwise turn
        { 
          counter ++;
        } else // counterclockwise turn
        {  
          counter --;
        } 
       } 
      
      aLastState = aState; // Updates the previous state of the outputA with the current state
//      previousMillis = currentMillis;
     //WriteToSerial();
  
    
  }

  int getCounter() {
    return counter;
  }

  void WriteToSerial()
  {
    Serial.print("Counter: ");
    Serial.println(counter);
  }
};
