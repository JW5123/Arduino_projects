#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

#define red A2
#define yellow A1
int green = 10;

int rock = 11;
int paper = 12;
int scissors = 13;
#define SPEAKER_PIN A3

void Playgame(){
    int bot_input = random(1, 4); //1=scissors,2=rock,3=paper
    int player_input;
    String outcome; // win, lose, withdraw
    //等待玩家input, 玩家按按鈕 while break
    while(true){
        if(digitalRead(rock) == LOW){
            player_input = 1;
            break;
        }
        if(digitalRead(paper) == LOW){
            player_input = 2;
            break;
        }
        if(digitalRead(scissors) == LOW){
            player_input = 3;
            break;
        }
    }
    //運算結果,比較bot_input和player_input並把結果寫在outcome裡
    if(player_input == 1){
        if(bot_input == 1){
            outcome = "withdraw";
        }
        if(bot_input == 2){
            outcome = "lose";
        }
        if(bot_input == 3){
            outcome = "win";
        }
    }else if(player_input == 2){
        if(bot_input == 1){
            outcome = "win";
        }
        if(bot_input == 2){
            outcome = "withdraw";
        }
        if(bot_input == 3){
            outcome = "lose";
        }
    }else{
        if(bot_input == 1){
            outcome = "lose";
        }
        if(bot_input == 2){
            outcome = "win";
        }
        if(bot_input == 3){
            outcome = "withdraw";
        }
    }
    //表示結果, 讀outcome 使用蜂鳴器，LED
    if(outcome == "win"){
        digitalWrite(green, HIGH);
        delay(1000);
        digitalWrite(green, LOW);
        tone(SPEAKER_PIN, 523); //C5
    }
    else if(outcome == "lose"){
        digitalWrite(red, HIGH);
        delay(1000);
        digitalWrite(red, LOW);
        tone(SPEAKER_PIN, 262); //C4
    }
    else{
        digitalWrite(yellow, HIGH);
        delay(1000);
        digitalWrite(yellow, LOW);
        tone(SPEAKER_PIN, 392); //G5
    }
    String name[] = {"Rock", "Paper", "Scissors"};
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Input:");
    lcd.print(name[player_input-1]);
    // lcd.setCursor(1,2);
    // lcd.print("bot_input: ");
    // lcd.print(name[bot_input-1]);
    lcd.setCursor(0, 1);
    lcd.print("Outcome:");
    lcd.print(outcome);
    delay((1000));
    noTone(SPEAKER_PIN);
}

void setup() {

    lcd.init();
    lcd.backlight();

    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

    pinMode(scissors, INPUT_PULLUP);
    pinMode(rock, INPUT_PULLUP);
    pinMode(paper, INPUT_PULLUP);

    randomSeed(analogRead(0));
}

void loop() {
    Playgame();
}