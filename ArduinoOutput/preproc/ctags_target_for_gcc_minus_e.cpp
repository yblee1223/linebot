# 1 "/Users/iyongbin/Repository/linebot/src/linetracer/linetracer.ino"
// InfraRed ray sensor




// Motor A connections Left




// Motor B connections Right




void linetracing();

void setup() {
    // Set all the motor control pins to outputs
    pinMode(9, 0x1);
    pinMode(3, 0x1);
    pinMode(8 /* ccw*/, 0x1);
    pinMode(7 /* cw*/, 0x1);
    pinMode(5 /* cw*/, 0x1);
    pinMode(4 /* ccw*/, 0x1);

    pinMode(10, 0x0);
    pinMode(11, 0x0);
    pinMode(12, 0x0);


    analogWrite(9, 255);
    analogWrite(3, 255);

    // Turn off motors - Initial state
    digitalWrite(8 /* ccw*/, 0x0);
    digitalWrite(7 /* cw*/, 0x0);
    digitalWrite(5 /* cw*/, 0x0);
    digitalWrite(4 /* ccw*/, 0x0);

    Serial.begin(9600);
    Serial.println("Hello linebot!");
}

void loop()
{
    linetracing();
}

void linetracing()
{
    int left_sensor = digitalRead(10);
    int middle_sensor = digitalRead(11);
    int right_sensor = digitalRead(12);

    Serial.println(left_sensor);
    Serial.println(right_sensor);

    // move forward
    if (left_sensor==0x1 && right_sensor==0x1){
        forward();
    }

    // control left
    else if (left_sensor==0x1 && right_sensor==0x0){
        left();
    }

    // control right
    else if (left_sensor==0x0 && right_sensor==0x1){
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
    digitalWrite(8 /* ccw*/, 0x0);
    digitalWrite(7 /* cw*/, 0x1);
    digitalWrite(5 /* cw*/, 0x1);
    digitalWrite(4 /* ccw*/, 0x0);
}

// backward
void backward(){
    Serial.println("backward");
    digitalWrite(8 /* ccw*/, 0x1);
    digitalWrite(7 /* cw*/, 0x0);
    digitalWrite(5 /* cw*/, 0x0);
    digitalWrite(4 /* ccw*/, 0x1);
}

// turn left
void left(){
    Serial.println("turn left");
    digitalWrite(8 /* ccw*/, 0x0);
    digitalWrite(7 /* cw*/, 0x1);
    digitalWrite(5 /* cw*/, 0x0);
    digitalWrite(4 /* ccw*/, 0x1);
}

// turn right
void right(){
    Serial.println("turn right");
    digitalWrite(8 /* ccw*/, 0x1);
    digitalWrite(7 /* cw*/, 0x0);
    digitalWrite(5 /* cw*/, 0x1);
    digitalWrite(4 /* ccw*/, 0x0);
}

// stop
void stop(){
    Serial.println("stop");
    digitalWrite(8 /* ccw*/, 0x0);
    digitalWrite(7 /* cw*/, 0x0);
    digitalWrite(5 /* cw*/, 0x0);
    digitalWrite(4 /* ccw*/, 0x0);
}
