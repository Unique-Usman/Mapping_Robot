//definining the pins
int motor1Pin1 = 11;
int motor1Pin2 = 3;
int motor2Pin1 = 6;
int motor2Pin2 = 5;
int ultrasonicTrigPin = 9;
int ultrasonicEchoPin = 10;
long duration;
int distance;

char frompi;

void setup() {
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
}

void forward() {
  // Code for moving forward
  analogWrite(motor1Pin1, 150);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 150);
}

void backward() {
  // Code for moving backward
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 150);
  analogWrite(motor2Pin1, 150);
  analogWrite(motor2Pin2, 0);
}

void left() {
  // Code for turning left
  analogWrite(motor1Pin1, 100);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 150);
  analogWrite(motor2Pin2, 0);
}

void right() {
  // Code for turning right
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 100);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 150);
}

void stopmotors() {
  // Code for stopping motors
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    frompi = data[0];
    Serial.print("You sent me: ");
    Serial.println(data);
  }

  if  (frompi == 'F') {
    forward();
  }
  else if (frompi == 'B') {
    backward();
  }
  else if (frompi == 'R') {
    right();
  }
  else if (frompi == 'L') {
    left();
  }
  else if (frompi == 'S') {
    stopmotors();
  }
  else {
    stopmotors();
  }
   
  Serial.flush();
}

