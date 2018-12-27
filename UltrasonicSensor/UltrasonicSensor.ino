/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPin =  LED_BUILTIN;// the number of the LED pin
const int analogueOutLED = 2; // Analog out pin for external LED

// For the stepmotor:
const int IN1 = 3;
const int IN2 = 4;
const int IN3  =5;
const int IN4 = 6;
int Steps = 4096; //4096 or 768
int cstep = 0;



// defines variables

long duration;
int distance;
int ledState = LOW;
int outputValue = 0; // For the external LED


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(ledPin, OUTPUT);

// Motor:
 pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 


Serial.begin(9600); // Starts the serial communication
}

void loop() {
  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

if (distance < 20){
  ledState = HIGH;
  outputValue = 200;
  
}
  else{
    ledState=LOW;
      outputValue = 0;

 }

analogWrite(analogueOutLED, outputValue);
digitalWrite(ledPin, ledState);


// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.println("ELLO");
Serial.println(outputValue);

//Motor:

 for(int x=0;x<Steps;x++)
  {
  step1();
  //delay(1);
  delayMicroseconds(2500);
  }
  Serial.println("Boom!!");
  delay(1000);
}
void step1()
{   
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);  
  }
