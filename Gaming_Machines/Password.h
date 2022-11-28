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

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

// void Password(){
//     char key = myKeypad.getKey();
//     if(key){
//         lcd.setCursor(0, 0);
//         lcd.print(key);
//         delay(1500);
//     }
//     lcd.clear();
// }
/*
int mode(){
    int num = 0;
    Serial.print("Input gamemode: ");
    char inp = myKeypad.getKey();
    if(inp == '1')
        num = 25;
    else if(inp == '2')
        num = 15;
    else if(inp == '3')
        num = 5;
    else{
        Serial.print("Input: ");
        char k = myKeypad.getKey();
        int num = k;
        Serial.print(num);
    }
    return num;
}
*/
/*
int number = random() % 10 + 1;
    int guess = 0, num = 0;
    num = mode();
    while(num--){
        Serial.print("Guess Number 0-100: ");
        char g = myKeypad.getKey();
        int guess = g;
        if(num == 0)
            break;
        if(guess > number)
            Serial.println("Guess to big !");
        else if(guess < number)
            Serial.println("Guess to small !");
        else{
            Serial.println("Guess right !");
        }
    }
*/