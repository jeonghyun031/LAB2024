int trig = 8;
int echo = 7;
int led = 13;

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    unsigned long duration = pulseIn(echo, HIGH);
    float distance = duration * 300 / 10000 /2;

    Serial.print(distance);
    Serial.println("CM");
    if (distance < 15) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
    delay(10);
}