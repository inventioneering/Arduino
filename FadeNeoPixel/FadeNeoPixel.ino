#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

int pulseDuration = 10;

int pulseBrightness = 255;

uint32_t darkBlue = strip.Color(9, 75, 108);
uint32_t lightBlue = strip.Color(65, 195, 255); 
uint32_t greyBlue = strip.Color(16, 129, 193); 
uint32_t blueGrey = strip.Color(75, 99, 107);
uint32_t hotPink = strip.Color(244, 20, 147);
//uint32_t peachPuff = strip.Color(255, 218, 185);
//uint32_t chartreuse = strip.Color(127,255,0);


void setup() {
  strip.begin();
  strip.show(); 
  }

void loop() {

//  pulseOneLed(0, greyBlue, pulseDuration);  
  
//  pulseRangeOfLeds(0,12,hotPink,pulseDuration);

  countUp();

}

void countUp() {
    for (int j = 0; j <= 12; j++) {
    pulseRangeOfLeds(0, j, greyBlue, pulseDuration);
    }
}



void pulseOneLed(int pixelNumber, uint32_t color, int duration) {
  for(int i = 0; i < pulseBrightness; i+=10) {
   
    strip.setBrightness(i);
    turnPixelOn(pixelNumber, color);
    delay(duration/2);
  }
  
   for(int i = pulseBrightness; i > 0; i-=10) {
    // gets a littler dimmer each time through the loop
    strip.setBrightness(i);
    turnPixelOn(pixelNumber, color);
    delay(duration/2);
  }
}

int setIncrementSize(int firstNeoPixel, int lastNeoPixel, int delayDuration) {
  int var = lastNeoPixel - firstNeoPixel;
  switch (var) {
    case 1:
      //do something when var equals 1
      return 10;
      break;
    case 2:
      //do something when var equals 2
      return 10;
      break;
    case 3:
      // do something when var equals 3
      return 5;
      break;
    case 4:
    // do something when var equals 3
    return 5;
    break;
    case 5:
    // do something when var equals 3
    return 5;
    break;
    default: 
      // if nothing else matches, do the default
      // default is optional
      return 1;
  }
}



int setDelayDuration(int incrementSize, int delayDuration) {
  int var = incrementSize;
  switch (var) {
    case 10:
    
      return delayDuration;
      break;
    case 5:
     
      return delayDuration/2;
      break;
    default: 
    
      return delayDuration/40;
  }
}


void pulseRangeOfLeds(int firstPixel, int lastPixel, uint32_t color, int duration) {

  int increment = setIncrementSize(firstPixel, lastPixel, duration);

  int adjustedTime = setDelayDuration(increment, duration);
  

  for(int i = 0; i < pulseBrightness; i+=increment) {
    strip.setBrightness(i);
    int pixel = firstPixel;
  
    while(pixel < lastPixel) {
      turnPixelOn(pixel, color);
      pixel++;
      }
    delay(adjustedTime);
  }
  
  for(int i = pulseBrightness; i > 0; i-=increment) {
    strip.setBrightness(i);
    int pixel = firstPixel;
    while(pixel < lastPixel) {
      turnPixelOn(pixel, color);
      pixel++;
      }
    delay(adjustedTime);
  }
  
}


void turnPixelOn(int pixelNumber, uint32_t pixelColor) {
  strip.setPixelColor(pixelNumber, pixelColor);
  strip.show();
}


void turnPixelOff(int pixelNumber) {
  strip.setPixelColor(pixelNumber, 0, 0, 0);
  strip.show();
}





