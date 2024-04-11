#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);


void setup()
{ 
  
  lcd.begin(16, 2); //Identifies the LCD's number of columns and rows
  
  lcd.print("Testing!");
}

void loop()
{
  lcd.setCursor(0,1); //Set the cursor to column 0, line 1
  
  lcd.print(millis() / 1000); //Print the number of seconds since reset
}
