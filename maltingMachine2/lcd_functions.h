 // 4 x 20 LCD
 #include <LiquidCrystal.h> 
 LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

 void setupLCD() {
   // LCD Setup
  lcd.print("Temperature:       ");
  lcd.setCursor(0,1);
  lcd.print("Humidity:          ");
  lcd.setCursor(0,2);
  lcd.print("Mode               ");
  lcd.setCursor(0,3);
  lcd.print("                   ");
 }

