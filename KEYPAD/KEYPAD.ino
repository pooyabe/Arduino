#include <Keypad.h>

const byte ROWS = 5;
const byte COLS = 4;
char hexaKeys[5][4] = {
  {'l','0','r','o'},
  {'7','8','9','e'},
  {'4','5','6','d'},
  {'1','2','3','u'},
  {'q','w','#','*'}
};
byte colPins[4] = {38, 37, 36, 35};
byte rowPins[5] = {34, 33, 32, 31, 30};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey == 'o'){
    Serial.println();
  }

  if (customKey && customKey != 'o'){
    Serial.print(customKey);
  }
}
