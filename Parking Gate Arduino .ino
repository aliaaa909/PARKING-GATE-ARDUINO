#include <Servo.h>

Servo myservo;
const int trigPin = 12;
const int echoPin = 11;
long duration;
float distance;

void setup() {
  myservo.attach(8);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo signal
  duration = pulseIn(echoPin, HIGH);
  
  // Debug print for duration
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.println(" ms");

  // Calculate distance (in cm)
  distance = (0.034 * duration) / 2;

  // Check if distance is correctly measured
  if (duration == 0) {
    Serial.println("No object detected or out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  if (distance <= 15 && duration > 0) {
    myservo.write(90);  // Move servo to 90 degrees
  } else {
    myservo.write(0);   // Move servo back to 0 degrees
  }

  delay(1500);
}
