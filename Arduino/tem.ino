int RGB_LED[] = {9,10,11};
int LOWER = 10;
int UPPER = 30;

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 3; i++)
    {
        pinMode(RGB_LED[i], OUTPUT);
    }
}

void loop() {
    int reading = analogRead(A1);
    float voltage = reading * 5.0 / 1024.0;
    Serial.print(voltage);
    Serial.print("V :");

    float temC = voltage * 100;
    Serial.print(temC);
    Serial.print("C: ");

    float temF = (temC * 9.0 / 5.0) + 32.0;
    Serial.print(temF);
    Serial.println(" F");

    if (temC < LOWER)
    {
        Serial.println("파랑색 켬");
        digitalWrite(RGB_LED[0], LOW);
        digitalWrite(RGB_LED[1], LOW);
        digitalWrite(RGB_LED[2], HIGH);
    }
    else if (temC > UPPER)
    {
        Serial.println("빨간색 켬");
        digitalWrite(RGB_LED[0], HIGH);
        digitalWrite(RGB_LED[1], LOW);
        digitalWrite(RGB_LED[2], LOW);
    }
    else
    {
        Serial.println("녹색 켬");
        digitalWrite(RGB_LED[0], LOW);
        digitalWrite(RGB_LED[1], HIGH);
        digitalWrite(RGB_LED[2], LOW);
    }
    delay(1000);
}