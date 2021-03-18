#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 11, en = 10, d0 = 9, d1 = 8, d2 = 7, d3 = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

const byte ROWS = 5;
const byte COLS = 4;
char hexaKeys[5][4] = {
  {'l', '0', 'r', 'e'},
  {'7', '8', '9', 'x'},
  {'4', '5', '6', 'd'},
  {'1', '2', '3', 'u'},
  {'w', 'q', '#', '*'}
};
byte colPins[4] = {30, 29, 28, 27};
byte rowPins[5] = {26, 25, 24, 23, 22};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int v1 = 0;

int GetNumber()
{
  int num = 0;
  char key = customKeypad.getKey();
  while (key != 'e')
  {
    switch (key)
    {
      case NO_KEY:
        break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        lcd.print(key);
        num = num * 10 + (key - '0');
        break;

      case 'x':
        num = 0;
        break;

    }

    key = customKeypad.getKey();
  }

  lcd.clear();
  lcd.print("Speed:  (RPS)");
  lcd.setCursor(0, 1);
  return num;
}



void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.blink();
  lcd.print("Speed:  (RPS)");
  lcd.setCursor(0, 1);
}
void loop() {

  v1 = GetNumber();
  Serial.println(v1);

}
