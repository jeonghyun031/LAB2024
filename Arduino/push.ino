// Digital Counter (1단계)

int LED = 13;                       //LED를 아두이노 13번 핀 연결
int SW = 7;                         //푸시 버튼 입력을 아두이노 7번 핀 연결

void setup() {
    pinMode(LED, OUTPUT);           //13번 핀(LED)을 출력으로 설정
    pinMode(SW, INPUT);             //7번 핀(SW)을 입력으로 설정
    Serial.begin(9600);             //시리얼 통신 초기화
}

void loop() {
    int state = digitalRead(SW);    /* 7번 핀(SW)으로 디지털 데이터를 입력 받아
                                        int형 변수 state에 저장*/

    if (state == HIGH) {            //변수 state에 저장된 값이 HIGH(버튼을 뗐을때)이면
        digitalWrite(LED, LOW);     //13번 핀(LED)으로 LOW(0V)를 출력
        Serial.println("SW : OFF"); //시리얼 모니터에 "SW : OFF" 출력 후 줄 바꿈
    }
    else {                          //변수 state에 저장된 값이 LOW(버튼 누름)이면
        digitalWrite(LED, HIGH);    //13번 핀(LED)으로 HIGH(5V)를 출력
        Serial.println("SW : ON");  //시리얼 모니터에 "SW : ON" 출력 후 줄 바꿈
    }
}