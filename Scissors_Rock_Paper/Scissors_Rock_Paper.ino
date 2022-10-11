int red = 2;
int yellow = 3;
int green = 4;

int scissors = 11;
int rock = 12;
int paper = 13;
#define SPEAKER_PIN 5

// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
    // LCD
  lcd.init();
  lcd.backlight();
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

void loop() {
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  int bot_input = random(1,4); //1=scissors,2=rock,3=paper
  int player_input;
  String outcome;//"win","lose","withdraw"

  //等待玩家input, 玩家按按鈕 while break
  while(true){
    if(digitalRead(scissors) == LOW){
      player_input = 1;
      break;
    }
    if(digitalRead(rock) == LOW){
      player_input = 2;
      break;
    }
    if(digitalRead(paper) == LOW){
      player_input = 3;
      break;
    }
  }
  
  //運算結果,比較bot_input和player_input並把結果寫在outcome裡
  if(player_input == 1){
    if(bot_input == 1){outcome = "withdraw";}
    if(bot_input == 2){outcome = "lose";}
    if(bot_input == 3){outcome = "win";}
  }else if(player_input == 2){
    if(bot_input == 1){outcome = "win";}
    if(bot_input == 2){outcome = "withdraw";}
    if(bot_input == 3){outcome = "lose";}
  }else{
    if(bot_input == 1){outcome = "lose";}
    if(bot_input == 2){outcome = "win";}
    if(bot_input == 3){outcome = "withdraw";}
  }

  //表示結果, 讀outcome 使用蜂鳴器，LED
  
  if(outcome == "win"){
    digitalWrite(green, HIGH);
    tone(SPEAKER_PIN, 523);//C5
  }else if(outcome == "lose"){
    digitalWrite(red, HIGH);
    tone(SPEAKER_PIN, 262);//C4
  }else{
    digitalWrite(yellow, HIGH);
    tone(SPEAKER_PIN, 392);//G5
  }
}
