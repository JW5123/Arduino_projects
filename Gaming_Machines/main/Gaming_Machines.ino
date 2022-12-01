// #include "Scissors_Rock_Paper.h"
// #include "Password.h"
// #include "Guess_Number.h"
// #include "Memory_Prifix.h"
// #include "Random_Change.h"
// #include "Menu.h"
#include <LiquidCrystal_I2C.h>
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

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define red A2
#define yellow A1
#define green 10
int scissors = 11;
int rock = 12;
int paper = 13;
#define SPEAKER_PIN A3

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


void Scissors_Rock_Paper(){

  int bot_input = random() % 3 + 1; // 1=scissors,2=rock,3=paper
  int player_input;
  String outcome; //"win","lose","withdraw"

  //等待玩家input, 玩家按按鈕 while break
  while (true){
    if (digitalRead(scissors) == LOW){
      player_input = 1;
      break;
    }
    if (digitalRead(rock) == LOW){
      player_input = 2;
      break;
    }
    if (digitalRead(paper) == LOW){
      player_input = 3;
      break;
    }
  }
  //運算結果,比較bot_input和player_input並把結果寫在outcome裡
  if (player_input == 1){
    if (bot_input == 1){
      outcome = "withdraw";
    }
    if (bot_input == 2){
      outcome = "lose";
    }
    if (bot_input == 3){
      outcome = "win";
    }
  }
  else if (player_input == 2){
    if (bot_input == 1){
      outcome = "win";
    }
    if (bot_input == 2){
      outcome = "withdraw";
    }
    if (bot_input == 3){
      outcome = "lose";
    }
  }
  else{
    if (bot_input == 1){
      outcome = "lose";
    }
    if (bot_input == 2){
      outcome = "win";
    }
    if (bot_input == 3){
      outcome = "withdraw";
    }
  }
  //表示結果, 讀outcome 使用蜂鳴器，LED
  String name[] = {"Scissors", "rock", "Paper"};

  if (outcome == "win"){
    digitalWrite(green, HIGH);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    Serial.println(outcome);
    tone(SPEAKER_PIN, 523); // C5
    delay(1500);
    digitalWrite(green, LOW);
  }
  else if (outcome == "lose"){
    digitalWrite(red, HIGH);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    Serial.println(outcome);
    tone(SPEAKER_PIN, 262); // C4
    delay(1500);
    digitalWrite(red, LOW);
  }
  else{
    digitalWrite(yellow, HIGH);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    Serial.println(outcome);
    tone(SPEAKER_PIN, 392); // G5
    delay(1500);
    digitalWrite(yellow, LOW);
  }
  lcd.clear();
  noTone(SPEAKER_PIN);
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
  lcd.setCursor(0, 0);
  lcd.print(k);
  lcd.clear();
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