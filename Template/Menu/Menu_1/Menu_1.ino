#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int upButton = 11;
int downButton = 13;
int selectButton = 12;
int menu = 1;

void setup() {

    lcd.init();
    lcd.backlight();

    pinMode(upButton, INPUT_PULLUP);
    pinMode(downButton, INPUT_PULLUP);
    pinMode(selectButton, INPUT_PULLUP);
    updateMenu();
}

void loop() {
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

void updateMenu() {
  switch (menu) {
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

void executeAction() {
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
    lcd.print(">Executing #1");
    delay(1500);
}
void action2() {
    lcd.clear();
    lcd.print(">Executing #2");
    delay(1500);
}
void action3() {
    lcd.clear();
    lcd.print(">Executing #3");
    delay(1500);
}
void action4() {
    lcd.clear();
    lcd.print(">Executing #4");
    delay(1500);
}
void action5() {
    lcd.clear();
    lcd.print(">Executing #5");
    delay(1500);
}



