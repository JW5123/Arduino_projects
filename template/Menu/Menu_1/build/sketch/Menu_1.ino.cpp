#include <Arduino.h>
#line 1 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define red A2
#define yellow A1
int green = 10;

int upButton = 11;
int downButton = 13;
int selectButton = 12;
int menu = 1;

#line 15 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void setup();
#line 30 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void loop();
#line 51 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void updateMenu();
#line 90 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void executeAction();
#line 110 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void action1();
#line 116 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void action2();
#line 122 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void action3();
#line 128 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void action4();
#line 133 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void action5();
#line 15 "/Users/renjiewang/Desktop/Embedded_System/Menu/Menu_1/Menu_1.ino"
void setup() {

    lcd.init();
    lcd.backlight();

    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

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
    lcd.print(">open red led");
    digitalWrite(red, HIGH);
    delay(1000);
}
void action2() {
    lcd.clear();
    lcd.print(">open yello led");
    digitalWrite(yellow, HIGH);
    delay(1000);
}
void action3() {
    lcd.clear();
    lcd.print(">open green led");
    digitalWrite(green, HIGH);
    delay(1000);
}
void action4() {
    lcd.clear();
    lcd.print(">Executing #4");
    delay(1500);
}
void action5() {
    lcd.clear();
    lcd.print(">close all led");
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    delay(1000);
}




