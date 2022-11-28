#include "Scissors_Rock_Paper.h"
// #include "Password.h"
// #include "Guess_Number.h"
// #include "Memory_Prifix.h"
// #include "Random_Change.h"
// #include "Menu.h"

#include <Keypad.h>

#define KEY_ROWS 4 
#define KEY_COLS 4
char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[KEY_ROWS] = {2, 3, 4, 5};
byte colPins[KEY_COLS] = {6, 7, 8, 9};

Keypad myKeypad1 = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
Keypad myKeypad2 = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

void setup()
{
  // LCD
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  // 初始化
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  //三個按鈕的初始化
  pinMode(scissors, INPUT_PULLUP);
  pinMode(rock, INPUT_PULLUP);
  pinMode(paper, INPUT_PULLUP);

  randomSeed(analogRead(0));
}

void Password(){
    char key = myKeypad2.getKey();
    if(key){
        lcd.setCursor(0, 0);
        lcd.print(key);
        delay(1500);
    }
    lcd.clear();
}


void loop()
{
  char k = myKeypad1.getKey();
  Serial.println(k);
  if(k == '1'){
    while(1){
      Scissors_Rock_Paper();
    }
  }
  else if(k == '2'){
    while(1){
      Password();
    }
  }
  // Menu();
  // Guess_Number();
  // Memory_Prifix();
  // Random_Change();
}