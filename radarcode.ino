#include <Servo.h>

const int trigPin = 8;
const int echoPin = 9;

// Defining time and distance
long duration;
int distance;

Servo myServo; // Create a servo object

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(10);       // Connects the servo on pin 10
}

void loop() {
  // Rotate from 15° to 165°
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  // Rotate back from 165° to 15°
  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Function to calculate the distance measured by the ultrasonic sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}