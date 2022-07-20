//開關及控制LED亮與暗
const int BUTTON_Pin = 2;
const int LED_Pin = 13;
const int ButtonDelay = 100;
int LED_State = LOW;
void setup(){
    pinMode(BUTTON_Pin, INPUT_PULLUP);
    pinMode(LED_Pin, OUTPUT);
}
void loop(){
    int val = digitalRead(BUTTON_Pin);
    if(val == LOW){
        delay(ButtonDelay);
        while(digitalRead(BUTTON_Pin) == LOW)
            ;                                   //等待放開按鍵
        LED_State = !LED_State;
        digitalWrite(LED_Pin, LED_State);
    }
}
