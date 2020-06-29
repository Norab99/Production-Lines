// There is PDF decument explain the movement of the box to sorted.

#include <Servo.h>

long duration1; 
long distance1;

long duration2; 
long distance2;

long length;      // The lenght of the box in the production lines.
long distance12; // The distance from sensor1 + the distance from sensor2.

// The trigger and echo pins that attached to sensor1.
int echoPin1 =8;
int trigPin1 =9;

// The trigger and echo pins that attached to sensor2.
int echoPin2 =5;
int trigPin2 =6;

Servo Motor1;
int MA =7;     // The pin that attached to the motor.

void setup() {
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Motor1.attach(MA);
  
}

void loop() {
  
  // Send the signal from sensor1 to the box.
  digitalWrite(trigPin1, LOW);
  delay(15);
  digitalWrite(trigPin1, HIGH);
  delay(10); 
  digitalWrite(trigPin1, LOW);
  
  /* Take the signal from sensor1 as a time duration
  that the signal take to go to the box and return. */
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;
  
  // Send the signal from sensor2 to the box.
  digitalWrite(trigPin2, LOW);
  delay(15);
  digitalWrite(trigPin2, HIGH);
  delay(10); 
  digitalWrite(trigPin2, LOW);
  
  /* Take the signal from sensor2 as a time duration
  that the signal take to go to the box and return. */
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  
  /* Detmine the length of the box by subtracting the addtion of the two
  distance from the distance between the two sensors which is equal to 336 cm in this circiut.*/
  distance12 = distance1 + distance2;  
  length = 336 - distance12;     
  
  if (length >=120 & length <=128){         // The range of the length of the box if it was 30cm.
    Motor1.write(90);                      // The box will go forward.
  }
  else if (length >=101 & length <=109){  // The range of the length of the box if it was 20cm.
    Motor1.write(180);                    // The box will go to the rigth.
  }
  else if (length >=83 & length <=91){   // The range of the length of the box if it was 10cm.
    Motor1.write(0);                     // The box will go to the left.
  }
  
}
