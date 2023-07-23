#include <Arduino.h>
#line 1 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
// InfraRed ray sensor
#define IRL 10 
#define IRM 11
#define IRR 12

// Motor A connections Left
#define enA 9
#define in1 8 // ccw
#define in2 7 // cw

// Motor B connections Right
#define enB 3
#define in3 5 // cw
#define in4 4 // ccw

void linetracing();

#line 18 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void setup();
#line 45 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void loop();
#line 80 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void forward();
#line 89 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void backward();
#line 98 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void left();
#line 107 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void right();
#line 116 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void stop();
#line 18 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
void setup() {
    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    pinMode(IRL, INPUT);
    pinMode(IRM, INPUT);
    pinMode(IRR, INPUT);

  
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    // Turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    Serial.begin(9600);
    Serial.println("Hello linebot!");
}

void loop() 
{
    linetracing();
}

void linetracing()
{
    int left_sensor = digitalRead(IRL);
    int middle_sensor = digitalRead(IRM);
    int right_sensor = digitalRead(IRR);
    
    Serial.println(left_sensor);
    Serial.println(right_sensor);

    // move forward
    if (left_sensor==HIGH && right_sensor==HIGH){
        forward();
    }

    // control left
    else if (left_sensor==HIGH && right_sensor==LOW){
        left();
    }

    // control right
    else if (left_sensor==LOW && right_sensor==HIGH){
        right();
    }

    // // stop
    // else if (left_sensor==LOW && middle_sensor==LOW && right_sensor==LOW){
    //     stop();
    // }
}
// forward
void forward(){
    Serial.println("forward");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// backward
void backward(){
    Serial.println("backward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

// turn left
void left(){
    Serial.println("turn left");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

// turn right
void right(){
    Serial.println("turn right");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// stop
void stop(){
    Serial.println("stop");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}






