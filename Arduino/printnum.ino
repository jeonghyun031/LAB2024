int printnumber = 0;
void setup() {
    Serial.begin(9600);
}
void loop() {
    Serial.print("The number is " + printnumber);
    printnumber++;
    delay(1000);
}