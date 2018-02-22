// temp/humidity sensor. See: https://learn.adafruit.com/dht?view=all
 #include "DHT.h" 

 #define DHTPIN 24
 #define DHTTYPE DHT11 
 DHT dht(DHTPIN, DHTTYPE);
 float h = 0;
 float t = 0;
 long previousDHTMillis = 0;
 long DHTCheckInterval = 5000;
 
void checkDHT() {
  unsigned long currentDHTMillis = millis();
  
  if(currentDHTMillis - previousDHTMillis >= DHTCheckInterval)
   {
   t = dht.readTemperature(true);
   h = dht.readHumidity();
     previousDHTMillis = currentDHTMillis;
   }
}


//float *readDHT()
//{
//   // Read temperature as Fahrenheit (isFahrenheit = true), takes 250milliseconds
//  unsigned long currentDHTMillis = millis();
//  float nH;
//  float nT;
//
//  if(currentDHTMillis - previousDHTMillis >= DHTCheckInterval)
//  {
//    static float array[2];
//    array[0] = dht.readHumidity();
//    array[1] = dht.readTemperature(true);
//    previousDHTMillis = currentDHTMillis;
//    return array;
//  } else {
//    static float array[2];
//    array[0] = -1;
//    array[1] = -1;
//    previousDHTMillis = currentDHTMillis;
//    return array;
//  }
//  
// 
//}
