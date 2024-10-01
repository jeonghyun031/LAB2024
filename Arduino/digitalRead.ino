//DigitalReadSerial

int pushbutton = 2;
void setup() {
    Serial.begin(9600);
    pinMode(pushbutton, INPUT);

}
void loop() {
    int buttonState = digitalRead(pushbutton);
    Serial.println(buttonState);
    delay(10);
}