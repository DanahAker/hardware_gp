#define PIN_ENA  32 // ESP32 pin GIOP14 connected to the EN1 pin L298N
#define PIN_IN1  33 // ESP32 pin GIOP27 connected to the IN1 pin L298N
#define PIN_IN2  25 // ESP32 pin GIOP26 connected to the IN2 pin L298N
#define PIN_IN3  26 // ESP32 pin GIOP27 connected to the IN3 pin L298N
#define PIN_IN4  27 // ESP32 pin GIOP26 connected to the IN4 pin L298N
#define PIN_ENB  14 // ESP32 pin GIOP14 connected to the EN2 pin L298N


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_IN1, HIGH); // control the motor's direction in clockwise
  digitalWrite(PIN_IN2, LOW);  // control the motor's direction in clockwise
  digitalWrite(PIN_IN3, LOW); // control the motor's direction in clockwise
  digitalWrite(PIN_IN4, HIGH);  // control the motor's direction in clockwise

  // for (int speed = 0; speed <= 255; speed++) {
   analogWrite(PIN_ENA, 255); // speed up
     analogWrite(PIN_ENB, 255); // speed up
  //   delay(10);
  // }

  // delay(2000); // rotate at maximum speed 2 seconds in clockwise direction

  // digitalWrite(PIN_IN1, LOW); // control the motor's direction in clockwise
  // digitalWrite(PIN_IN2, HIGH);  // control the motor's direction in clockwise
  // digitalWrite(PIN_IN3, HIGH); // control the motor's direction in clockwise
  // digitalWrite(PIN_IN4, LOW);  // control the motor's direction in clockwise

  // for (int speed = 255; speed >= 0; speed--) {
  //   analogWrite(PIN_ENA, speed); // speed down
  //   analogWrite(PIN_ENB, speed); // speed down
  //   delay(10);
  // }

  // delay(2000); // stop motor 2 second
}