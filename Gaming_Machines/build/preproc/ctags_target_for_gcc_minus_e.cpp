# 1 "/Users/renjiewang/Desktop/Arduino/Scissors_Rock_Paper/Scissors_Rock_Paper.ino"
int red = 2;
int yellow = 3;
int green = 4;

int scissors = 11;
int rock = 12;
int paper = 13;


// LCD
# 12 "/Users/renjiewang/Desktop/Arduino/Scissors_Rock_Paper/Scissors_Rock_Paper.ino" 2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 選項 1 --> 猜拳
void SRP(){
  int bot_input = random() % 3 + 1; // 1=scissors,2=rock,3=paper
  int player_input;
  String outcome; //"win","lose","withdraw"

  //等待玩家input, 玩家按按鈕 while break
  while (true)
  {
    if (digitalRead(scissors) == 0x0)
    {
      player_input = 1;
      break;
    }
    if (digitalRead(rock) == 0x0)
    {
      player_input = 2;
      break;
    }
    if (digitalRead(paper) == 0x0)
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
    digitalWrite(green, 0x1);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    tone(5, 523); // C5
    delay(1500);
    digitalWrite(green, 0x0);
  }
  else if (outcome == "lose"){
    digitalWrite(red, 0x1);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    tone(5, 262); // C4
    delay(1500);
    digitalWrite(red, 0x0);
  }
  else{
    digitalWrite(yellow, 0x1);
    lcd.setCursor(0, 0); // 設定遊標位置 (左邊數第幾個字, 行數)
    lcd.print("Input:");
    lcd.print(name[player_input - 1]);
    lcd.setCursor(0, 1); // 1,3
    lcd.print("Outcome:");
    lcd.print(outcome);
    tone(5, 392); // G5
    delay(1500);
    digitalWrite(yellow, 0x0);
  }
  lcd.clear();
  noTone(5);
}

// 選項 2 --> 終極密碼
void Password(){
  //程式碼待寫區
}
// 選項 3 --> 1A2B猜數字
void Guess_Number(){
  //程式碼待寫區
}
// 選項 4 --> 記憶前綴和
void Memory_Prfix(){
  //程式碼待寫區
}
// 選項 5 --> 
void Random_change(){
  //程式碼待寫區
}

void setup()
{
  // LCD
  lcd.init();
  lcd.backlight();
  // 初始化
  pinMode(red, 0x1);
  pinMode(yellow, 0x1);
  pinMode(green, 0x1);
  //三個按鈕的初始化
  pinMode(scissors, 0x2);
  pinMode(rock, 0x2);
  pinMode(paper, 0x2);

  randomSeed(analogRead(0));
}

void loop()
{
  SRP();
  Password()
  Guess_Number()
  Memory_Prfix()
  Random_change()
}
