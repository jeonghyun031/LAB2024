int segmentLEDs[] = { 58, 59, 60, 61, 62, 63, 64, 65};
int segmentLEDsNUM = 8;

int digitForNum[10][8] = 8;

int digitForNum[10][8] = { {1,1,1,1,1,1,,0,0}, {0,1,1,0,0,0,0,0}, {1,1,0,1,1,0,1,0}, {1,1,1,1,0,0,1,0}, {0,1,1,0,0,1,1,0},
                        {1,0,1,1,1,1,1,0}, {1,0,1,1,1,1,1,1,0}, {1,1,1,0,0,0,0,0}, {1,1,1,1,1,1,1,0}, {1,1,1,1,0,1,1,0}};

void setup() {
    for (int i = 0; i < segmentLEDsNUM ; i++) {
        pinMode(segmentLEDs[i], OUTPUT);
    }
}

void loop() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < segmentLEDsNUM; j++) {
            digitalWrite(segmentLEDs[j], digitForNum[i][j]);
        }
        delay(1000);
    }
}