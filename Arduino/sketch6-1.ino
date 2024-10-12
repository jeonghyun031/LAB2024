int potPin = A0;
int ledPin = 13;
in val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(potPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    val = analogRead(potPin);
    Serial.println(val);
    digitalWrite(ledPin, HIGH);
    delay(val);
    digitalWrite(ledPin, LOW);
    delay(val);
}