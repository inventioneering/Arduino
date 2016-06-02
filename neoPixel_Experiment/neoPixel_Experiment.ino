#include <Adafruit_NeoPixel.h>

#define PIN 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

uint32_t darkBlue = strip.Color(9, 75, 108);
uint32_t hotPink = strip.Color(244, 20, 147);

void setup() {
  // put your setup code here, to run once:
  strip.begin();

}

uint32_t sadColors(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  return strip.Color(0, 0, WheelPos);
 
}

void loop()
{
  rainbow(100);
  //allOneColor(hotPink);
  
}

void allOneColor(uint32_t c)
{
  for(int i = 0; i<12; i++)
  {
    strip.setPixelColor(i,c);
  }
  strip.show();
  
}

void chase(int delayTime, uint32_t c)
{
  for(int i = 0; i < 12; i++)
  {
    strip.setPixelColor(i,c); // turn on one
    strip.show();  // show
    delay(delayTime); // wait
    strip.setPixelColor(i,0,0,0);// turn off current one
    strip.setPixelColor(i+1,c);// turn on next one
    delay(delayTime);// wait
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      //strip.setPixelColor(i, Wheel((i+j) & 255));
      strip.setPixelColor(i, sadColors((i+j) & 255));
      strip.show();
      
    }
    //strip.show();
    //delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

