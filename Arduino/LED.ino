int led =13;
int mtime = 1000;
void setup() {
    pimMode(led, OUTPUT);
}
void loop() {
    digitalWrite(led, HIGH);
    delay(mtime);
    digitalWrite(led, LOW);
    delay(mtime);
}