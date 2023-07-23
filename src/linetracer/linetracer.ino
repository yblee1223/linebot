// InfraRed ray sensor
#define IRL 10 
#define IRM 11
#define IRR 12

// Motor A connections Left
#define enA 9
#define A_ccw 8 // ccw
#define A_cw 7 // cw

// Motor B connections Right
#define enB 3
#define B_cw 5 // cw
#define B_ccw 4 // ccw

const int baseSpeed = 150;
const int correctionValue = 50;

void linetracing();

void setup() {
    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(A_ccw, OUTPUT);
    pinMode(A_cw, OUTPUT);
    pinMode(B_cw, OUTPUT);
    pinMode(B_ccw, OUTPUT);

    pinMode(IRL, INPUT);
    pinMode(IRM, INPUT);
    pinMode(IRR, INPUT);

  
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    // Turn off motors - Initial state
    digitalWrite(A_ccw, LOW);
    digitalWrite(A_cw, LOW);
    digitalWrite(B_cw, LOW);
    digitalWrite(B_ccw, LOW);

    Serial.begin(9600);
    Serial.println("Hello linebot!");
}

void loop() 
{
    linetracing();
}

void linetracing()
{
    int leftLineValue = analogRead(IRL);
    int rightLineValue = analogRead(IRR);

    // 읽은 값들을 시리얼 모니터에 표시 (디버깅용)
    Serial.print("Left Sensor: ");
    Serial.print(leftLineValue);
    Serial.print(" | Right Sensor: ");
    Serial.println(rightLineValue);

    // 라인 센서의 값에 따라 모터 속도 조절
    int leftSpeed = baseSpeed - (leftLineValue - rightLineValue) / 2 - correctionValue;
    int rightSpeed = baseSpeed + (leftLineValue - rightLineValue) / 2 + correctionValue;

    // 모터 속도가 0보다 작으면 0으로 설정
    leftSpeed = max(leftSpeed, 0);
    rightSpeed = max(rightSpeed, 0);

    // 모터 속도가 255보다 크면 255로 설정
    leftSpeed = min(leftSpeed, 255);
    rightSpeed = min(rightSpeed, 255);

    // 모터 속도를 설정하여 라인 트레이서가 직진하게 함
    analogWrite(enA, leftSpeed);
    analogWrite(enB, rightSpeed);
}

void speedUp(int en, int speed)
{
    for (int i = 0; i < 256; i++) {
        analogWrite(en, i);
        delay(20);
    }
}

void speedDown(int en, int speed)
{
    for (int i = 255; i >= 0; --i) {
        analogWrite(en, i);
        delay(20);
    }
}





