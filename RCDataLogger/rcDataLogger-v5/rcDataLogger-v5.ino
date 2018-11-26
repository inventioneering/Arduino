#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
String fileName;
String readString;
String dataString = "";
String consoleString = "";
float calculatedMPH = 0;

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();
const int chipSelect = 4;

void setup() {
  
  fileName = "rc.txt";
  
  pinMode(13, OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  if(Serial) {
    Serial.print("Initializing SD card...");
  }
  

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    if(Serial) {
      Serial.println("Card failed, or not present");
    }
    
    // don't do anything more:
    return;
  }
  if(Serial) {
    Serial.println("card initialized.");
    Serial.println("Adafruit_MPL3115A2 test!");
  }
  

  File dataFile = SD.open(fileName, FILE_WRITE);
  String tabCharacter = "\t";
  String header = "Altitude(ft),Time(s),Speed(MPH)";
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(tabCharacter);
    dataFile.println(header);
    dataFile.close();
    // print to the serial port too:
    if(Serial) {
       Serial.println(header);
    }
   
  }
}

void loop() {
  
  
  if (! baro.begin()) {
    if(Serial) {
       Serial.println("Couldnt find sensor");
       Serial.println("Starting time in seconds: " + millis()/1000);
    }
     
      return;
    }

      // make a string for assembling the data to log:
     String dataString = "";

     //float pascals = baro.getPressure();
  // Our weather page presents pressure in Inches (Hg)
  // Use http://www.onlineconversion.com/pressure.htm for other units
 // Serial.print(pascals/3377); Serial.println(" Inches (Hg)");

  float altm = baro.getAltitude();
  //Serial.print(altm); Serial.println(" meters");

  //float tempC = baro.getTemperature();
  //Serial.print(tempC); Serial.println("*C");

  // get pressure & calculate airspeed
  dataString = "";
  float reading = analogRead(0);
  float vOut = 5 * (0.2*reading+0.5);
  float mph = 0.32246*vOut - 280.839;  // inverse of our function: https://www.desmos.com/calculator/aze1yror77


  // put data in string formatted, "pressure,altitude,temperature"
 
  dataString += String(altm*3.28);
  dataString += ",";
  dataString += String(millis()/1000);
  dataString += ",";
  dataString += String(mph);


  digitalWrite(13, HIGH);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  
  
  File dataFile = SD.open(fileName, FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    if(Serial) {
       Serial.println(dataString);
    }
    digitalWrite(13, LOW);
  }
  // if the file isn't open, pop up an error:
  else {
    if (Serial) {
      Serial.println("error opening datalog.txt");
    }
    
  }
}











