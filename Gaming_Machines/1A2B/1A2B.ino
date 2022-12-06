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
byte rowPins[KEY_ROWS] = {9, 8, 7, 6};
byte colPins[KEY_COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String guessNum = "";
bool acceptkey = true;

int a, b, c, d;
int e, f, g, h;
char A[4], B[4];

void Home(){
    lcd.setCursor(0, 0);
    lcd.print(" Welcome to the");
    lcd.setCursor(6, 1);
    lcd.print("1A2B");
    delay(2000);
    lcd.clear();
}

void PlayGame(){
    int res = 0;

    do{
        a = random(1, 10);
        b = random(0, 10);
        c = random(0, 10);
        d = random(0, 10);
    }while((a == b) || (a == c) || (a == d) || (b == c) || (b == d) || (c == d));

    int number = (a * 1000) + (b * 100) + (c * 10) + d;

    Serial.println(number);

    while(true){
        int countA = 0, countB = 0;
        lcd.setCursor(0, 0);
        lcd.print("Your guess:");
        acceptkey = true;
        guessNum = "";
        while(true){
            char num = myKeypad.getKey();
            if(acceptkey && num != NO_KEY){
                if(num == '#'){
                    acceptkey = false;
                    int guess = atoi(guessNum.c_str());

                    e = guess / 1000;
                    f = (guess - e * 1000) / 100;
                    g = (guess - e * 1000 - f * 100) / 10;
                    h = guess - e * 1000 - f * 100 - g * 10;

                    if(guess == number){
                        res = 1;
                        break;
                    }
                    else if(guess >= 1000 && guess < 10000 && (e == f || e == g || e == h || f == g || g == h)){
                        res = 2;
                        break;
                    }
                    else if(guess < 1000 || guess >= 10000){
                        res = 3;
                        break;
                    }
                    else{
                        if(a == e)
                            countA = ++countA;
                        if(b == f)
                            countA = ++countA;
                        if(c == g)
                            countA = ++ countA;
                        if(d == h)
                            countA = ++ countA;
                        if(e == b || e == c || e == d)
                            countB = ++countB;
                        if(f == a || f == c || f == d)
                            countB = ++countB;
                        if(g == a || g == b || g == d)
                            countB = ++countB;
                        if(h == a || h == b || h == c)
                            countB = ++countB;

                        res = 4;
                        break;
                    }
                }
                else{
                    guessNum += num;
                    lcd.print(num);
                }
            }
        }
        int flag = 0;
        if(res == 1){
            lcd.setCursor(0, 1);
            lcd.print("Bingo!!");
            delay(2000);
            flag = 1;
        }
        else if(res == 2){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Nums cannot same");
            lcd.setCursor(0, 1);
            lcd.print("Enter nums again");
            delay(2000);
            lcd.clear();
        }
        else if(res == 3){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Error!! Please");
            lcd.setCursor(0, 1);
            lcd.print("enter a 4 digits");
            delay(2000);
            lcd.clear();
        }
        else if(res == 4){
            lcd.setCursor(0, 1);
            sprintf(A, "%dA", countA);
            lcd.print(A);
            lcd.setCursor(2, 1);
            sprintf(B, "%dB", countB);
            lcd.print(B);
            delay(2000);
            lcd.clear();
        }
        if(flag == 1){
            lcd.clear();
            break;
        }
    }
}

void setup()
{
    Serial.begin(115200);

    lcd.init();
    lcd.backlight();
    
    randomSeed(analogRead(0));
    Home();
}

void loop()
{
    PlayGame();
}
