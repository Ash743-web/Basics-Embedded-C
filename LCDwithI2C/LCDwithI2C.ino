#include <LiquidCrystal_I2C.h>
 
// Create the lcd object address 0x3F and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2);  //
 
void  setup () {
   // Initialize the LCD connected 
  lcd. init ();
  
  // Turn on the backlight on LCD. 
  lcd. backlight ();
  
  // print the Message on the LCD. 
 /* lcd.setCursor(2,0);
  lcd.print ( "Welcome to" );
  lcd.setCursor(4,1);
  lcd.print("GHRCEM");
  delay(3000);
  lcd.clear();*/
 
}
 
void  loop () {
    //Here cursor is placed on first position (col: 0) of the second line (row: 1) 
   lcd.setCursor(2,0);
  lcd.print ( "Welcome to" );
  lcd.setCursor(4,1);
  lcd.print("GHRCEM");
  delay(3000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("My name is");
  lcd. setCursor (4,1);
  lcd.print("Ashwini");
   // We write the number of seconds elapsed 
  delay (3000);
  lcd.clear();
}

