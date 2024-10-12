int redPin = 3;
int greenPin = 5;
int bluePin = 6;

int redControl = A0;
int greenControl = A1;
int blueControl = A2;

int redVal, GreenVal, blueVal;

void setup() {
    pinMode(redPin,OUTPUT);
    pinMode(greenPin,OUTPUT);
    pinMode(bluePin,OUTPUT);

    Serial.begin(9600);
}

void loop() {
    redVal = analogRead(redControl);
    GreenVal = analogRead(greenControl);
    blueVal = analogRead(blueControl);

    redVal = map(redVal, 0 , 1023, 0, 255);
    GreenVal = map(GreenVal, 0, 1023, 0, 255);
    blueVal = map(blueVal, 0, 1023, 0, 255);

    setColor(redVal, GreenVal, blueVal);

    Serial.print(" - Red: ");
    Serial.print(redVal);
    Serial.print(" - Green: ");
    Serial.print(GreenVal);
    Serial.print(" - Blue: ");
    Serial.print(blueVal);
}

void setColor(int redValue, int greenValue, int blueValue) {
    analogWrite(redPin,redValue);
    analogWrite(greenPin,greenValue);
    analogWrite(bluePin,blueValue);
}