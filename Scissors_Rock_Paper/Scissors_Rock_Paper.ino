int red = 2;
int yellow = 3;
int green = 4;

int scissors = 11;
int rock = 12;
int paper = 13;
#define SPEAKER_PIN 5

// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// option 1
void SRP(){
  int bot_input = random() % 3 + 1; // 1=scissors,2=rock,3=paper
  int player_input;
  String outcome; //"win","lose","withdraw"

  //等待玩家input, 玩家按按鈕 while break
  while (true)
  {
    if (digitalRead(scissors) == LOW)
    {
      player_input = 1;
      break;
    }
    if (digitalRead(rock) == LOW)
    {
      player_input = 2;
      break;
    }
    if (digitalRead(paper) == LOW)
    {
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
    tone(SPEAKER_PIN, 392); // G5
    delay(1500);
    digitalWrite(yellow, LOW);
  }
  lcd.clear();
  //  lcd.setCursor(1,2);
  //  lcd.print("bot_input: ");
  //  lcd.print(name[bot_input-1]);
  //  lcd.setCursor(0,0);//1,3
  //  lcd.print("outcome:");
  //  lcd.print(outcome);
  // delay((1000));
  noTone(SPEAKER_PIN);
}

// option 2

// option 3

// option 4

// option 5

void setup()
{
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

void loop()
{
  SRP();
}