#include "Scissors_Rock_Paper.h"
// #include "Password.h"
// #include "Guess_Number.h"
// #include "Memory_Prifix.h"
// #include "Random_Change.h"
// #include "Menu.h"

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

void loop()
{
  // Menu();
  Scissors_Rock_Paper();
  // Password();
  // Guess_Number();
  // Memory_Prifix();
  // Random_Change();
}