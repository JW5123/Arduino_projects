# 1 "/Users/renjiewang/Documents/GitHub/Arduino_projects/Gaming_Machines/Gaming_Machines.ino"
# 2 "/Users/renjiewang/Documents/GitHub/Arduino_projects/Gaming_Machines/Gaming_Machines.ino" 2
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
  pinMode(A2, 0x1);
  pinMode(A1, 0x1);
  pinMode(10, 0x1);
  //三個按鈕的初始化
  pinMode(scissors, 0x2);
  pinMode(rock, 0x2);
  pinMode(paper, 0x2);

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
