// Digital Counter(3단계)

int LED = 13;                           //LED를 아두이노 13번 핀에 연결
int SW =7;                              //푸시 버튼을 아두이노 7번 핀에 연결
int num = 0;                                /* 푸시 버튼이 눌린 횟수를 저장한 int형
                                            num을 선언*/
boolean check = 0;                      //초기값 false로 설정

void setup() {
    pinMode(LED, OUTPUT);               //13번핀(LED)을 출력으로 설정
    pinMode(SW, INPUT);                  //7번 핀(SW)을 입력을 설정
    Serial.begin(9600);                 // 시리얼 통신 초기화
}   
void loop() {
    int state = digitalRead(SW);

    if (state == HIGH) {                //변수 state에 저장된 값이 HIGH(버튼 뗌)일때
        digitalWrite(LED, LOW);         //13번 핀(LED)으로 LOW(0V)를 출력
        Serial.println("SW : OFF");     //시리얼 모니터에 "SW : OFF" 출력 후 줄 바꿈
        Serial.print("num = ");         //시리얼 모니터에 "num = " 문자열 출력
        Serial.print(num);              //시리얼 모니터에 num 값 출력 후 줄 바꿈
        check = false;
    }
    else {                              //변수 state에 저장된 값이 LOW(버튼 누름)일때
        if (check == false) {           //변수 check에 저장된 값이 false이면
            num = num + 1;              //num에 저장된 값이 1만큼 증가
            check = true;               //변수 check에 저장된 값을 true로 변경
        }
        num += 1;                       //푸시 버튼이 늘리면 num이 1씩 증가
        digitalWrite(LED, HIGH);        //13번 핀(LED)으로 HIGH(5V)를 출력
        Serial.println("SW : ON");      //시리얼 모니터에 "SW : ON" 출력 후 줄 바꿈
        Serial.print("num =");          //시리얼 모니터에 "num = " 문자열 출력
        Serial.println(num);            //시리얼 모니터에 num에 저장된 값 출력
        
    }
}