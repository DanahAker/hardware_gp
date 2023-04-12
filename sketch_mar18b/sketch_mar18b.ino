// www.YouTube.com/Electronics is Fun //

// #include<Servo.h>
#define   LEFT 2
#define echopin  4// echo pin
#define trigpin 0 // Trigger pin
#define   RIGHT 15

#define enA  32 // ESP32 pin GIOP14 connected to the EN1 pin L298N
#define PIN_IN1  33 // ESP32 pin GIOP27 connected to the IN1 pin L298N
#define PIN_IN2  25 // ESP32 pin GIOP26 connected to the IN2 pin L298N
#define PIN_IN3  26 // ESP32 pin GIOP27 connected to the IN3 pin L298N
#define PIN_IN4  27 // ESP32 pin GIOP26 connected to the IN4 pin L298N
#define enB  14 // ESP32 pin GIOP14 connected to the EN2 pin L298N
#define myservo 16

// Servo myservo;
   
int pos =0, Speed=130;
int t;

void setup(){

  pinMode(enA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(enB, OUTPUT);

Serial.begin(9600);
// myservo.attach(35);

// for(pos   = 90; pos <= 180; pos += 1){
// servoPulse(myservo, pos);
// delay(15);
// }
 
// for(pos   = 180; pos >= 0; pos-= 1) {
// servoPulse(myservo, pos);
// delay(15);
// }

// for(pos   = 0; pos<=90; pos += 1) {
// servoPulse(myservo, pos);
// delay(15);
// }

// pinMode(RIGHT,   INPUT);
// pinMode(LEFT, INPUT);

// pinMode(trigpin, OUTPUT);
// pinMode(echopin,   INPUT);

}

void loop(){
unsigned int distance = read_cm();

int   Right_Value = digitalRead(RIGHT);
int Left_Value  = digitalRead(LEFT);

Serial.print("R=   ");
Serial.print(Right_Value);
Serial.print(" L= ");
Serial.print(Left_Value);
Serial.print("   D= ");
Serial.println(distance);

if((digitalRead(RIGHT) == 0)&&(digitalRead(LEFT) == 0)){forword();}  //if Right Sensor and Left Sensor are at White color then it will call forword function
if((digitalRead(RIGHT) == 1)&&(digitalRead(LEFT) == 0)){turnLeft();}//if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
if((digitalRead(RIGHT) == 0)&&(digitalRead(LEFT) == 1)){turnRight();} //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
if((digitalRead(RIGHT) == 1)&&(digitalRead(LEFT) == 1)){Stop();}     //if Right Sensor and Left Sensor are at Black color then it will call Stop function
// forword();
delay(50);
}

long read_cm(){
   digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,   HIGH);
  delayMicroseconds(10);
  t = pulseIn (echopin, HIGH);
  return   t / 29 / 2;
}

void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      // Convert angle to microseconds
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50);                   // Refresh cycle of servo
}

void forword(){// turn it on going forward
Serial.print("in forward");

digitalWrite(PIN_IN1, HIGH); //Right Motor forword Pin 
digitalWrite(PIN_IN2, LOW);  //Right Motor backword Pin 

digitalWrite(PIN_IN3, LOW);  //Left Motor backword Pin 
digitalWrite(PIN_IN4, HIGH); //Left Motor forword Pin 
analogWrite(enA, 255); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 

analogWrite(enB, 255); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
//  for (int speed = 0; speed <= 255; speed++) {
//     analogWrite(enA, speed); // speed up
//     analogWrite(enB, speed); // speed up
//     delay(10);
//   }
delay(2000);
}

void   backword(){ // the other way
digitalWrite(PIN_IN1, LOW);  //Right Motor forword Pin 
digitalWrite(PIN_IN2, HIGH); //Right Motor backword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
digitalWrite(PIN_IN3, HIGH); //Left Motor backword Pin 
digitalWrite(PIN_IN4, LOW);  //Left Motor forword Pin 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void turnRight(){   // the other right
digitalWrite(PIN_IN1, LOW);  //Right Motor forword Pin 
digitalWrite(PIN_IN2, HIGH); //Right Motor backword Pin
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
digitalWrite(PIN_IN3, LOW);  //Left Motor backword Pin 
digitalWrite(PIN_IN4, HIGH); //Left Motor forword Pin 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void   turnLeft(){ // turn it on going left
digitalWrite(PIN_IN1, HIGH); //Right Motor forword Pin 
digitalWrite(PIN_IN2, LOW);  //Right Motor backword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
digitalWrite(PIN_IN3, HIGH); //Left Motor backword Pin 
digitalWrite(PIN_IN4, LOW);  //Left Motor forword Pin 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void   Stop(){ // stopped
digitalWrite(PIN_IN1, LOW); //Right Motor forword Pin 
digitalWrite(PIN_IN2, LOW); //Right Motor backword Pin 
analogWrite(enA, 0); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
digitalWrite(PIN_IN3, LOW); //Left Motor backword Pin 
digitalWrite(PIN_IN4, LOW); //Left Motor forword Pin  
analogWrite(enB, 0); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}
