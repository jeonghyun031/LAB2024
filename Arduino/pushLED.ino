int pin_LED[] = {5, 6};
int pin_button[] = {14, 15};
void setup() {
    Serial.begin(9600);
    for ( int i = 0 ; i < 2 ; i++) {
        boolean state = digitalRead(pin_button[i]);
        digitalWrite(pin_LED[i], state);
        Serial.print(state);
        Serial.print(" ");
    }
    Serial.println();
    delay(1000);
}