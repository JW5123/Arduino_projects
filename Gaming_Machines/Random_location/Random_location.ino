#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

//*****game5 var*****
int life = 3;
int score = 0;
int goal;
int pos = 1;
int dect = 1;
int speed = 500;
int gameover_timer = 8;
int game5button = 12; //change here
//*******************
void updatelcd(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Life:");
    lcd.print(life);
    lcd.print("  ");
    lcd.print("Score:");
    lcd.print(score);
    lcd.setCursor(0, 1);
    lcd.print("----------------");
    lcd.setCursor(goal, 2);
    lcd.print("*");
    /*
    if(score == 0){
        lcd.setCursor(0, 3);
        lcd.print("Tip: holding button");
    }
    if(score == 1){
        lcd.setCursor(0, 3);
        lcd.print("Tip: press before *");
    }
    */
}
void game5_init(){
    lcd.clear();
    life = 3;
    score = 0;
    speed = 500;
    //gameover_timer = 8;
    randomSeed(analogRead(1));
    goal = random(3, 16);
}
void game5(){
    game5_init();
    while(true){
        updatelcd();
        while(digitalRead(12) == HIGH){
            delay(speed);
            lcd.setCursor(pos, 1);
            lcd.print("|");
            lcd.setCursor(pos - dect, 1);
            lcd.print("-");
            lcd.setCursor(goal, 1);
            lcd.print("*");
            if(pos == 15 || pos == 0){
                dect = dect * -1;
            }
            pos = pos + dect;
        }
        if(pos - dect == goal){
            score++;
            speed = speed * 8 / 10;
            lcd.setCursor(0, 1);
            lcd.print("Win");
        }else{
            life--;
            lcd.setCursor(0, 1);
            lcd.print("Lose");
        }
        delay(2000);
        if(life == -1){
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("Gameover");
            lcd.setCursor(4, 1);
            lcd.print("Score:");
            lcd.print(score);
            while(gameover_timer != 0){
                delay(1000);
                gameover_timer--;
            }
            break;
        }
    }
}

void setup() {

    lcd.init();
    lcd.backlight();

    pinMode(game5button, INPUT_PULLUP);
}

void loop() {

    game5();
}