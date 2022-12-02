#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <time.h>

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

String modeNum = "";
String guessNum = "";
int game_mode = 0;
bool acceptKey = true;

char score1[100], score2[100];
int computer = 0, player = 0;

// mode option
void ModeChoose(){
    lcd.setCursor(3, 0);
    lcd.print("Game mode");
    lcd.setCursor(0, 1);
    lcd.print("[1] [2] [3] [4]");
    while(true){
        char choice = myKeypad.getKey();
        if(choice == '1'){
            lcd.clear();
            game_mode = 1;
            lcd.setCursor(0, 1);
            lcd.print("[1]");
            delay(1000);
            break;
        }
        if(choice == '2'){
            lcd.clear();
            game_mode = 2;
            lcd.setCursor(4, 1);
            lcd.print("[2]");
            delay(1000);
            break;
        }
        if(choice == '3'){
            lcd.clear();
            game_mode = 3;
            lcd.setCursor(8, 1);
            lcd.print("[3]");
            delay(1000);
            break;
        }
        if(choice == '4'){
            lcd.clear();
            game_mode = 4;
            lcd.setCursor(12, 1);
            lcd.print("[4]");
            delay(1000);
            break;
        }
    }
    lcd.clear();
}

// Mode4
int Mode4(){
    int num = 0;
    int res = 0;
    int n = 1;
    while(true){
        lcd.setCursor(0, 0);
        lcd.print("Input times:");
        acceptKey = true;
        modeNum = "";
        while(true){
            char inp = myKeypad.getKey();
            if(acceptKey && inp != NO_KEY){
                if(inp == '#'){
                    acceptKey = false;
                    int times = atoi(modeNum.c_str());
                    int errorNum[] = {0, 65, 67, 68, 69, 35, 32};   // Not numbers
                    if(times == NULL){
                        for(int i = 0; i < errorNum; i++){
                            if(times == errorNum[i])
                                res = 1;
                                break;
                        }
                        break;
                    }
                    else{
                        res = 2;
                        num = times;
                        break;
                    }
                }
                else{
                    modeNum += inp;
                    lcd.print(inp);
                }
            }
        }
        int flag = 0;
        lcd.setCursor(0, 1);
        if(res == 1){
            lcd.print("Input error!!");
        }
        if(res == 2){
            lcd.print("Setting success");
            flag = 1;
        }
        delay(1000);
        lcd.clear();
        if(flag == 1){
            break;
        }
    }
    return num;
}

// all mode
int All_mode(){
    int num = 0;
    if(game_mode == 1){
        num = 25;
        lcd.setCursor(0, 0);
        lcd.print("Guess times:");
        lcd.print(num);
        delay(1000);
        lcd.clear();
    }
    else if(game_mode == 2){
        num = 15;
        lcd.setCursor(0, 0);
        lcd.print("Guess times:");
        lcd.print(num);
        delay(1000);
        lcd.clear();
    }
    else if(game_mode == 3){
        num = 5;
        lcd.setCursor(0, 0);
        lcd.print("Guess times:");
        lcd.print(num);
        delay(1000);
        lcd.clear();
    }
    else if(game_mode == 4){
        num = Mode4();  //call Mode4 function
    }
    return num;
}

// start guess
void PlayGame(){
    int errorNum[] = {0, 65, 67, 68, 69, 35, 32};   // Not numbers
    long number = random(1, 101);
    int num = All_mode();
    int res = 0;
    int flag = 0;
    for(int i = 1; i <= num; i++){
        lcd.setCursor(0, 0);
        lcd.print("Your Guess:");
        acceptKey = true;
        guessNum = "";
        while(true){
            char key = myKeypad.getKey();
            if(acceptKey && key != NO_KEY){
                if(key == '#'){
                    lcd.setCursor(0, 1);
                    acceptKey = false;
                    int guess = atoi(guessNum.c_str());
                    // lcd.print(number);
                    // delay(500);
                    if(num == 0){
                        break;
                    }
                    if(guess == NULL){
                        for(int i = 0; i < errorNum; i++){
                            if(guess == errorNum[i]){
                                res = 1;
                                break;
                            }
                        }
                        break;
                    }
                    if(guess > number){
                        res = 2;
                        break;
                    }
                    else if(guess < number){
                        res = 3;
                        break;
                    }
                    else{
                        res = 4;
                        break;
                    }
                    lcd.clear();
                }
                else{ 
                    guessNum += key;
                    lcd.print(key);
                }
            }
        }
        lcd.setCursor(0, 1);
        if(res == 1){
            lcd.print("Error Re-enter!!");  // Have a bug in current
        }
        else if(res == 2){
            lcd.print("Guess to big!!");
        }
        else if(res == 3){
            lcd.print("Guess to small!!");
        }
        else if(res == 4){
            lcd.print("Guess right!!");
            flag = 1;
        }
        delay(1000);
        lcd.clear();
        if(num == 0 || flag == 1){
            break;
        }else{
            continue;
        }
    }
    lcd.setCursor(3, 0);
    if(flag == 1){
        lcd.print("You Win!!");
        player++;
    }
    else{
        lcd.print("You Lose!!");
        computer++;
    }
    delay(1200);
    lcd.clear();
    lcd.setCursor(0, 0);
    sprintf(score1, "Computer:%d", computer);
    lcd.print(score1);
    lcd.setCursor(0, 1);
    sprintf(score2, "Player:%d", player);
    lcd.print(score2);
    delay(1500);
    lcd.clear();
}

void setup()
{
    lcd.init();
    lcd.backlight();
  
    lcd.setCursor(3, 0);
    lcd.print("Welcome to");
    lcd.setCursor(0, 1);
    lcd.print("Guess nums game");
    delay(1500);
    lcd.clear();

    randomSeed(analogRead(0));

}
void loop()
{
    // call function
    ModeChoose();
    PlayGame();
}