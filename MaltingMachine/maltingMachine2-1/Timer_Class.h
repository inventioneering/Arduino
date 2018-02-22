class Timer
{
  // Data
  long timerLength;  // in milliseconds
  unsigned long previousMillis;   // will store last time encoder was updated
  
  // Constructor
  public:
  Timer(long tLengthSeconds)
  {
    timerLength = tLengthSeconds*1000;
    previousMillis = 0;
  }

  // Methods
  void resetTimer(long tLengthSeconds) {
    timerLength = tLengthSeconds*1000;
    previousMillis = millis();
  }
  
  boolean timerRunningQ() 
  {
    if(millis() - previousMillis <= timerLength)
    {
      return true;
    } 
    else 
    {
      return false;
    }
  }

  long secondsLeft() {
    
    if(timerRunningQ() == true) {
      return (timerLength - (millis()-previousMillis))/1000;
    } else {
      return 0;
    }
    
  }
};
