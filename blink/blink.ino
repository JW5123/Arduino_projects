int LED_pin = 13;

void setup() {     
  pinMode(LED_pin, OUTPUT); 
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_pin, HIGH);
  //Serial.println("HIGH");
  delay(100);                      
  digitalWrite(LED_pin, LOW);
  //Serial.println("LOW");
  delay(100);                       
}