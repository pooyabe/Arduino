// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, d0 = 6, d1 = 7 , d2 = 8, d3 = 9;
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

String text = "Saeed Azadi";
long var = 123456789;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {
  /*
  lcd.clear();
  
  lcd.home();
  lcd.print("Pooya Behravesh");
  lcd.setCursor(0, 1);
  lcd.print(">Electron");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);
  lcd.setCursor(0, 1);
  lcd.print(var);
  delay(2000);
  
  lcd.cursor();
  lcd.blink();
  
  lcd.clear();
  lcd.home();
  lcd.print("Arduino");
  lcd.scrollDisplayRight();
  delay(400);
  lcd.scrollDisplayRight();
  delay(400);
  lcd.scrollDisplayRight();
  delay(2000);
  
  lcd.noCursor();
  lcd.noBlink();
  
  lcd.scrollDisplayLeft();
  delay(400);
  lcd.scrollDisplayLeft();
  delay(400);
  lcd.scrollDisplayLeft();
  delay(2000);
  
  lcd.noDisplay();
  delay(2000);
  
  lcd.display();
  lcd.clear();
  lcd.home();
  lcd.print("Hello!!!");
  delay(2000);
  */
  if (Serial.available()) {
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
  
}
