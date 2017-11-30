 // Mode timer
 int modeOneTimer = 300;

String modeName(int mode) {
  if(mode == 1) {
    return "1 - Germination";
  } else if (mode == 2) {
    return "2 - Kiln       ";
  }
}

lcdPrintRowColumn(String message, int row, int column) {
  lcd.setCursor(column,row);
  lcd.print(message);
}

void lcdPrint(int mode, float hh, float tt,int counter) {
  if(mode == 1) 
  {
    lcdPrintRowColumn("Temperature: ",0,0);         // ROW 1:  show temp
    lcdPrintRowColumn((String)tt,0,13);             
    lcdPrintRowColumn((String)hh,1,10);             // ROW 2:  show humidity
    lcdPrintRowColumn((String)modeName(mode),2,5);  // ROW 3: show mode
    lcdPrintRowColumn("Time Remaining: ",3,0);      // ROW 4: show time remaining mode 1
    lcdPrintRowColumn((String)12345,3,16);
  } 
  
  else if (mode == 2) 
  {
    lcdPrintRowColumn("Temperature: ",0,0);         // ROW 1:  show temp
    lcdPrintRowColumn((String)tt,0,13); 
    lcdPrintRowColumn((String)hh,1,10);             // ROW 2:  show humidity
    lcdPrintRowColumn((String)modeName(mode),2,5);  // ROW 3: show mode
    lcdPrintRowColumn("Goal Temp:           ",3,0);          // ROW 4: show time remaining mode 1
    lcdPrintRowColumn((String)counter,3,12);

  } 
}
