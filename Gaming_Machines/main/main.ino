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

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// LED Pin
#define red A1
#define yellow A2
#define green 10

int upButton = 11, rock = 11, G_Button = 11;
int selectButton = 12, paper = 12, Y_Button = 12;
int downButton = 13, scissors = 13, R_Button = 13;
// Buzzer Pin
#define SPEAKER_PIN A3

// Scissors rock paper
int rock_1 = 0;
int paper_1 = 1;
#define scissors_1 A0
int pla = 0, com = 0;

// guess_the_num
String modeNum = "";
String guessNum = "";
int game_mode = 0;
bool acceptKey = true;
// int errorNum[] = {0, 65, 67, 68, 69, 35, 32};   // Not numbers

char score1[100], score2[100];
int computer = 0, player = 0;

// 1A2B
String guess_1A2B = "";
bool acceptkey = true;
int a, b, c, d;
int e, f, g, h;
char A[4], B[4];


// Random location
int life = 3;
int score = 0;
int goal;
int pos = 1;
int dect = 1;
int speed = 500;
int game5button = 12; //change here


int menu = 1;
/******************************************* Scissors rock paper ******************************************/

int Roundmode = 0;
void Roundup(){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Rounds mode");
    lcd.setCursor(0, 1);
    lcd.print("[1] [2] [3] [4]");
    while(true){
        char choose = myKeypad.getKey();
        if(choose == '1'){
            pla = 0, com = 0;
            lcd.clear();
            Roundmode = 1;
            lcd.setCursor(0, 1);
            lcd.print("[1]");
            delay(1000);
            break;
        }
        if(choose == '2'){
            pla = 0, com = 0;
            lcd.clear();
            Roundmode = 2;
            lcd.setCursor(4, 1);
            lcd.print("[2]");
            delay(1000);
            break;
        }
        if(choose == '3'){
            pla = 0, com = 0;
            lcd.clear();
            Roundmode = 3;
            lcd.setCursor(8, 1);
            lcd.print("[3]");
            delay(1000);
            break;
        }
        if(choose == '4'){
            pla = 0, com = 0;
            lcd.clear();
            Roundmode = 4;
            lcd.setCursor(12, 1);
            lcd.print("[4]");
            delay(1000);
            break;
        }
    }
    lcd.clear();
}

int PressTimes(){
    int num = 0;
    if(Roundmode == 1){
        num = 3;
        lcd.setCursor(0, 0);
        lcd.print(num);
        lcd.print(" Rounds");
        delay(1000);
        lcd.clear();
    }
    if(Roundmode == 2){
        num = 5;
        lcd.setCursor(0, 0);
        lcd.print(num);
        lcd.print(" Rounds");
        delay(1000);
        lcd.clear();
    }
    if(Roundmode == 3){
        num = 7;
        lcd.setCursor(0, 0);
        lcd.print(num);
        lcd.print(" Rounds");
        delay(1000);
        lcd.clear();
    }
    if(Roundmode == 4){
        num = 9;
        lcd.setCursor(0, 0);
        lcd.print(num);
        lcd.print(" Rounds");
        delay(1000);
        lcd.clear();
    }
    return num;
}

void PlayGame1(){
    // int bot_input = random(1, 4);
    int player1_input, player2_input;
    String outcome;

    int player_1 = 0, player_2 = 0;
    char times1[20], times2[20];

    int num = PressTimes();
    int flag = 0;
    int res = 0;
    int n = 0;

    if(num == 3)
        n = 2;
    if(num == 5)
        n = 3;
    if(num == 7)
        n = 4;
    if(num == 9)
        n = 5;
    for(int i = 1; i <= num; i++){
        while(true){
            if(digitalRead(rock_1) == LOW){
                player2_input = 1;
                digitalWrite(green, HIGH);
                delay(1000);
                digitalWrite(green, LOW);
                break;
            }
            if(digitalRead(paper_1) == LOW){
                player2_input = 2;
                digitalWrite(green, HIGH);
                delay(1000);
                digitalWrite(green, LOW);
                break;
            }
            if(digitalRead(scissors_1) == LOW){
                player2_input = 3;
                digitalWrite(green, HIGH);
                delay(1000);
                digitalWrite(green, LOW);
                break;
            }
        }
        while(true){
            if(digitalRead(rock) == LOW){
                player1_input = 1;
                break;
            }
            if(digitalRead(paper) == LOW){
                player1_input = 2;
                break;
            }
            if(digitalRead(scissors) == LOW){
                player1_input = 3;
                break;
            }
        }
        if(player1_input == 1){
            if(player2_input == 1){
                outcome = "withdraw";
            }
            if(player2_input == 2){
                outcome = "lose";
            }
            if(player2_input == 3){
                outcome = "win";
            }
        }else if(player1_input == 2){
            if(player2_input == 1){
                outcome = "win";
            }
            if(player2_input == 2){
                outcome = "withdraw";
            }
            if(player2_input == 3){
                outcome = "lose";
            }
        }else{
            if(player2_input == 1){
                outcome = "lose";
            }
            if(player2_input == 2){
                outcome = "win";
            }
            if(player2_input == 3){
                outcome = "withdraw";
            }
        }
        if(outcome == "win"){
            digitalWrite(green, HIGH);
            tone(SPEAKER_PIN, 523);
            delay(1000);
            digitalWrite(green, LOW);
            player_1++;
        }
        else if(outcome == "lose"){
            digitalWrite(red, HIGH);
            tone(SPEAKER_PIN, 262);
            delay(1000);
            digitalWrite(red, LOW);
            player_2++;
        }
        else{
            digitalWrite(yellow, HIGH);
            tone(SPEAKER_PIN, 392);
            delay(1000);
            digitalWrite(yellow, LOW);
            num++;
        }
        String name[] = {"Rock", "Paper", "Scissors"};
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You:");
        lcd.print(name[player1_input - 1]);
        lcd.setCursor(0, 1);
        lcd.print("Admin:");
        lcd.print(name[player2_input - 1]);
        // lcd.print("Outcome:");
        // lcd.print(outcome);
        noTone(SPEAKER_PIN);
        delay(1000);
        // Serial.println(player_1);
        // Serial.println(player_2);
        if(player_1 >= n){
            res = 1;
            break;
        }
        else if(player_2 >= n){
            res = 2;
            break;
        }
    }
    lcd.clear();
    lcd.setCursor(3, 0);
    if(res == 1){
        lcd.print("You Win!!");
        pla++;
    }
    else{
        lcd.print("You Lose!!");
        com++;
    }
    delay(1500);
    lcd.clear();
    lcd.setCursor(0, 0);
    sprintf(times1, "You:%d", pla);
    lcd.print(times1);
    lcd.setCursor(0, 1);
    sprintf(times2, "Admin:%d", com);
    lcd.print(times2);
    delay(2000);
}

/******************************************** Guess the number ********************************************/

// mode option
void ModeChoose(){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Guess mode");
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
                    if(times > 100 || times <= 0){
                        res = 1;
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
void PlayGame2(){
    int number = random(1, 101);
    int num = All_mode();
    int res = 0;
    int flag = 0;
    int guesstimes = 0;
    for(int i = 1; i <= num; i++){
        lcd.setCursor(0, 0);
        lcd.print("Your Guess:");
        acceptKey = true;
        guessNum = "";
        while(true){
            char key = myKeypad.getKey();
            if(acceptKey && key != NO_KEY){
                if(key == '#'){
                    acceptKey = false;
                    int guess = atoi(guessNum.c_str());
                    //lcd.setCursor(0, 1);
                    // lcd.print(number);
                    // delay(500);
                    if(num == 0){
                        break;
                    }
                    if(guess > 100 || guess <= 0){
                        res = 1;
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
            lcd.print("Error Re-enter!!");
            num++;
            guesstimes++;
        }
        else if(res == 2){
            lcd.print("Guess to big!!");
            guesstimes++;
        }
        else if(res == 3){
            lcd.print("Guess to small!!");
            guesstimes++;
        }
        else if(res == 4){
            lcd.print("Guess right!!");
            guesstimes++;
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
    lcd.print("Guess times:");
    lcd.print(guesstimes);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    sprintf(score2, "Player:%d", player);
    lcd.print(score2);
    lcd.setCursor(0, 1);
    sprintf(score1, "Computer:%d", computer);
    lcd.print(score1);
    delay(2000);
}

/************************************************** 1A2B **************************************************/

void Home(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Welcome to the");
    lcd.setCursor(6, 1);
    lcd.print("1A2B");
    delay(2000);
    lcd.clear();
}

void PlayGame3(){
    int res = 0;
    int times = 0;

    randomSeed(analogRead(0));
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
        guess_1A2B = "";
        while(true){
            char num = myKeypad.getKey();
            if(acceptkey && num != NO_KEY){
                if(num == '#'){
                    acceptkey = false;
                    int guess = atoi(guess_1A2B.c_str());

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
                    guess_1A2B += num;
                    lcd.print(num);
                }
            }
        }
        int flag = 0;
        if(res == 1){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("4A0B");
            lcd.setCursor(0, 1);
            lcd.print("Bingo!!");
            tone(SPEAKER_PIN, 1046);
            delay(300);
            tone(SPEAKER_PIN, 1245);
            delay(1000);
            noTone(SPEAKER_PIN);
            lcd.clear();
            times++;
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
            times++;
        }
        else if(res == 3){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Error!! Please");
            lcd.setCursor(0, 1);
            lcd.print("enter a 4 digits");
            delay(2000);
            lcd.clear();
            times++;
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
            times++;
        }
        if(flag == 1){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Guess times:");
            lcd.print(times);
            delay(2000);
            lcd.clear();
            break;
        }
    }
}

/****************************************** Prefix_Memorization *******************************************/

void PlayGame4() {
    String ans;         // ans
    int score = 0;      // total score
    int i;              // rounds
    int j;              // led

    lcd.setCursor(0, 0);
    lcd.print("Start: Press #");
    while(true){
        char s = myKeypad.getKey();
        if(s == '#'){
            lcd.clear();
            lcd.setCursor(5, 0);
            lcd.print("Start");
            delay(2000);
            lcd.clear();
            for(i = 0; i < 30; ++i) {
                int num;

                if(i < 3) 
                    num = random(1, 3);
                else 
                    num = random(1, 4);

                for(int j = 0; j < num; ++j) {
                    int color = random(1, 4);

                    if(color == 1) { 
                        ans += '1';
                        digitalWrite(red, HIGH);
                        delay(1500);
                        digitalWrite(red, LOW);
                        delay(300);
                    }
                    else if(color == 2) {
                        ans += '2';
                        digitalWrite(yellow, HIGH);
                        delay(1500);
                        digitalWrite(yellow, LOW);
                        delay(300);
                    }
                    else if(color == 3) {
                        ans += '3';
                        digitalWrite(green, HIGH);
                        delay(1500);
                        digitalWrite(green, LOW);
                        delay(300);
                    }
                }

                Serial.print("ans = ");
                Serial.println(ans);

                bool win = true; 
                for(j = 0; j < ans.length(); ++j) {
                    bool correct = true;
                    while(true) {
                        if(digitalRead(R_Button) == LOW) {
                            if(ans[j] != '1') 
                                correct = false;
                            digitalWrite(red, HIGH);
                            delay(200);
                            digitalWrite(red, LOW);
                            break;
                        }
                        if(digitalRead(Y_Button) == LOW) {
                            if(ans[j] != '2') 
                                correct = false;
                            digitalWrite(yellow, HIGH);
                            delay(200);
                            digitalWrite(yellow, LOW);
                            break;
                        }
                        if(digitalRead(G_Button) == LOW) {
                            if(ans[j] != '3') 
                                correct = false;
                            digitalWrite(green, HIGH);
                            delay(200);
                            digitalWrite(green, LOW);
                            break;
                        }
                    }
                    if(!correct) {  // 按錯燈
                        tone(SPEAKER_PIN, 262);
                        delay(1000);
                        noTone(SPEAKER_PIN);
                        win = false;
                        break;
                    }
                }
                delay(1000);

                lcd.setCursor(0, 0);
                lcd.print("Score +");
                lcd.print(j);
                score += j;

                lcd.setCursor(0, 1);
                lcd.print("Score:");
                lcd.print(score);
                delay(2000);

                if(!win){
                    lcd.clear();
                    lcd.setCursor(2, 0);
                    lcd.print("Game Over!!!");
                    break;
                }
            }
            delay(1000);

            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print(i + 1);
            if(i == 0 || i == 1) 
                lcd.print(" Round.");
            else 
                lcd.print(" Rounds.");

            lcd.setCursor(4, 1);
            lcd.print("Score:");
            lcd.print(score);
            delay(2500);
            lcd.clear();
            
            delay(500);
            break;
        }
    }
}

/********************************************* Random location ********************************************/

void updatelcd(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Life:");
    lcd.print(life);
    lcd.print("  ");
    lcd.print("Score:");
    lcd.print(score);
    lcd.setCursor(0, 1);
    lcd.print("----------------");
    lcd.setCursor(goal, 1);
    lcd.print("*");
}
void game5_init(){
    lcd.clear();
    life = 3;
    score = 0;
    speed = 500;
    randomSeed(analogRead(0));
    goal = random(1, 16);
}
void PlayGame5(){

    lcd.setCursor(0, 0);
    lcd.print("Start: Press #");
    while(true){
        char s = myKeypad.getKey();
        if(s == '#'){
            lcd.clear();
            lcd.setCursor(5, 0);
            lcd.print("Start");
            delay(1000);
            lcd.clear();
            game5_init();
            while(true){
                updatelcd();
                while(digitalRead(12) == HIGH){
                    delay(speed);
                    lcd.setCursor(pos, 1);
                    lcd.print("O");
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
                    goal = random(3, 12);
                    lcd.setCursor(0, 1);
                    lcd.print("-------Win------");
                }
                else{
                    life--;
                    goal = random(3, 12);
                    lcd.setCursor(0, 1);
                    lcd.print("------Lose------");
                    tone(SPEAKER_PIN, 262);
                    delay(1000);
                    noTone(SPEAKER_PIN);
                }
                delay(1000);
                if(life == -1){
                    lcd.clear();
                    lcd.setCursor(4, 0);
                    lcd.print("Gameover");
                    lcd.setCursor(4, 1);
                    lcd.print("Score:");
                    lcd.print(score);
                    delay(3000);
                    break;
                }
            }
            break;
        }
    }
}

/***************************************** Menu placement area ********************************************/
void updateMenu(){
    switch(menu){
        case 0:
            menu = 1;
            break;
        case 1:
            lcd.clear();
            lcd.print(">Game 1");
            lcd.setCursor(0, 1);
            lcd.print(" Game 2");
            break;
        case 2:
            lcd.clear();
            lcd.print(" Game 1");
            lcd.setCursor(0, 1);
            lcd.print(">Game 2");
            break;
        case 3:
            lcd.clear();
            lcd.print(">Game 3");
            lcd.setCursor(0, 1);
            lcd.print(" Game 4");
            break;
        case 4:
            lcd.clear();
            lcd.print(" Game 3");
            lcd.setCursor(0, 1);
            lcd.print(">Game 4");
            break;
        case 5:
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(">Game 5");
        case 6:
            menu = 5;
            break;
    }
}

void executeAction(){
    switch (menu) {
        case 1:
            action1();
            break;
        case 2:
            action2();
            break;
        case 3:
            action3();
            break;
        case 4:
            action4();
            break;
        case 5:
            action5();
            break;
    }
}

void action1() {
    lcd.clear();
    lcd.print(">Choose game1");
    delay(1000);
    lcd.clear();
    while(true){
        Roundup();
        PlayGame1();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        int flag = 0;
        while(true){
            char p1 = myKeypad.getKey();
            if(p1 == 'A'){
                flag = 1;
                break;
            }
            if(p1 == 'B'){
                flag = 2;
                break;
            }
        }
        if(flag == 1)
            continue;
        else
            break;
    }
}

void action2() {
    lcd.clear();
    lcd.print(">Choose game2");
    delay(1000);
    lcd.clear();
    start:
    while(true){
        ModeChoose();
        PlayGame2();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        int flag = 0;
        while(true){
            char p2 = myKeypad.getKey();
            if(p2 == 'A'){
                goto start;
            }
            if(p2 == 'B'){
                flag = 1;
                break;
            }
        }
        if(flag = 1)
            break;
    }
}
void action3() {
    lcd.clear();
    lcd.print(">Choose game3");
    delay(1000);
    lcd.clear();
    int flag = 0;
    start:
    while(true){
        Home();
        PlayGame3();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        while(true){
            char p3 = myKeypad.getKey();
            if(p3 == 'A'){
                goto start;
            }
            if(p3 == 'B'){
                flag = 1;
                break;
            }
        }
        if(flag = 1)
            break;
    }
}
void action4() {
    lcd.clear();
    lcd.print(">Choose game4");
    delay(1000);
    int flag = 0;
    start:
    while(true){
        PlayGame4();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        while(true){
            char p4 = myKeypad.getKey();
            if(p4 == 'A'){
                goto start;
            }
            if(p4 == 'B'){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
}

void action5() {
    lcd.clear();
    lcd.print(">Choose game5");
    delay(1000);
    int flag = 0;
    start:
    while(true){
        PlayGame5();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        while(true){
            char p5 = myKeypad.getKey();
            if(p5 == 'A'){
                goto start;
            }
            if(p5 == 'B'){
                flag = 1;
                break;
            }
        }
        if(flag = 1)
            break;
    }
}

void MenuButton(){
    if (!digitalRead(downButton)){
        menu++;
        updateMenu();
        delay(100);
        while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton)){
        menu--;
        updateMenu();
        delay(100);
        while(!digitalRead(upButton));
    }
    if (!digitalRead(selectButton)){
        executeAction();
        updateMenu();
        delay(100);
        while (!digitalRead(selectButton));
    }
}
/**********************************************************************************************************/

void setup(){

    lcd.init();
    lcd.backlight();

    Serial.begin(9600);

    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

    pinMode(upButton, INPUT_PULLUP);    // rock
    pinMode(selectButton, INPUT_PULLUP);  //scissors && game5button
    pinMode(downButton, INPUT_PULLUP);  // paper

    pinMode(rock_1, INPUT_PULLUP);
    pinMode(paper_1, INPUT_PULLUP);
    pinMode(scissors_1, INPUT_PULLUP);

    randomSeed(analogRead(0));

    updateMenu();
}

void loop(){
    MenuButton();
}
