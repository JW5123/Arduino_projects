#define R_LED A2
#define Y_LED A1
#define G_LED 10

int R_Button = 13;
int Y_Button = 12;
int G_Button = 11;

void Prefix_Memorization()
{
    String ans;    // ans
    int score = 0; // total score
    int i;         // rounds
    int j;         // led

    for (i = 0; i < 30; ++i){
        int num;

        if (i < 3)
            num = random(1, 3);
        else
            num = random(1, 4);
        // Serial.print("num=");
        // Serial.println(num);

        for (int j = 0; j < num; ++j){
            int color = random(1, 4); // 1 -> red 2 -> yellow 3 -> green
            // Serial.print("color=");
            // Serial.println(color);

            if (color == 1){
                ans += '1';

                digitalWrite(R_LED, HIGH);
                delay(1500);
                digitalWrite(R_LED, LOW);
                delay(200);
            }
            else if (color == 2){
                ans += '2';

                digitalWrite(Y_LED, HIGH);
                delay(1500);
                digitalWrite(Y_LED, LOW);
                delay(200);
            }
            else if (color == 3){
                ans += '3';

                digitalWrite(G_LED, HIGH);
                delay(1500);
                digitalWrite(G_LED, LOW);
                delay(200);
            }
        }
        Serial.print("ans = ");
        Serial.println(ans);

        bool win = true; // wether correct in this round
        for (j = 0; j < ans.length(); ++j){
            bool correct = true; // wether correct by press this button
            while(true){
                if (digitalRead(R_Button) == LOW){
                    if (ans[j] != '1')
                        correct = false;

                    digitalWrite(R_LED, HIGH); // display player led
                    delay(200);
                    digitalWrite(R_LED, LOW);

                    break;
                }

                if (digitalRead(Y_Button) == LOW){
                    if (ans[j] != '2')
                        correct = false;

                    digitalWrite(Y_LED, HIGH);
                    delay(200);
                    digitalWrite(Y_LED, LOW);

                    break;
                }

                if (digitalRead(G_Button) == LOW){
                    if (ans[j] != '3')
                        correct = false;

                    digitalWrite(G_LED, HIGH);
                    delay(200);
                    digitalWrite(G_LED, LOW);

                    break;
                }
            }
            if (!correct){
                win = false;
                break;
            }
        }

        delay(1000);

        Serial.print("Score + ");
        Serial.println(j);
        score += j;

        Serial.print("Score : ");
        Serial.println(score);

        delay(2000);

        if (!win){
            Serial.println("Game Over!!!");
            break;
        }
    }
    delay(1000);

    Serial.print(i + 1);
    if (i == 0 || i == 1)
        Serial.println(" Round.");
    else
        Serial.println(" Rounds.");

    Serial.print("Score : ");
    Serial.println(score);

    delay(500);
}
void setup(){
    Serial.begin(115200);

    pinMode(R_LED, OUTPUT);
    pinMode(Y_LED, OUTPUT);
    pinMode(G_LED, OUTPUT);

    pinMode(R_Button, INPUT_PULLUP);
    pinMode(Y_Button, INPUT_PULLUP);
    pinMode(G_Button, INPUT_PULLUP);

    randomSeed(analogRead(0));
}
void loop(){

    delay(2000);
    Prefix_Memorization();
}