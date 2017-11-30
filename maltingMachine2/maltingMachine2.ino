
#include "Flasher_Class.h"
#include "Rotary_Class.h"

 // temp/humidity sensor. See: https://learn.adafruit.com/dht?view=all
 #include "DHT.h" 
 #define DHTPIN 24
 #define DHTTYPE DHT11 
 DHT dht(DHTPIN, DHTTYPE);
 float h = 0;
 float t = 0;
 long previousDHTMillis = 0;
 long DHTCheckInterval = 1000;



RotaryEncoder rotary(2, 3, 22, 200);

void setup()
{
  Serial.begin(57600);
}

void loop()
{
   rotary.Update();
   
  unsigned long currentDHTMillis = millis();
  
  if(currentDHTMillis - previousDHTMillis >= DHTCheckInterval)
   {
   t = dht.readTemperature(true);
    h = dht.readHumidity();
     previousDHTMillis = currentDHTMillis;
   }

    Serial.print("(humidity, temperature, counter): ");
    Serial.print("(");
    Serial.print(h);
    Serial.print(", ");
    Serial.print(t);
    Serial.print(", ");
    Serial.print(rotary.getCounter());
    Serial.println(")");

//      Serial.println(rotary.getCounter());
//      Serial.println(h);
//      Serial.println(t);
  
}

float getTemp() {
  // Read temperature as Fahrenheit (isFahrenheit = true), takes 250milliseconds
  delay(250);
  return dht.readTemperature(true);
}

float getHumidity() {
  // Reading humidity, 250 milliseconds
  delay(250);
  return dht.readHumidity();
}


float *readDHT()
{
   // Read temperature as Fahrenheit (isFahrenheit = true), takes 250milliseconds
  unsigned long currentDHTMillis = millis();
  float nH;
  float nT;

  if(currentDHTMillis - previousDHTMillis >= DHTCheckInterval)
  {
    static float array[2];
    array[0] = dht.readHumidity();
    array[1] = dht.readTemperature(true);
    previousDHTMillis = currentDHTMillis;
    return array;
  } else {
    static float array[2];
    array[0] = -1;
    array[1] = -1;
    previousDHTMillis = currentDHTMillis;
    return array;
  }
  
 
}


