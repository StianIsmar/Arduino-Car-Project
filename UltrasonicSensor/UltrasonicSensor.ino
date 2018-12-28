/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 8;
const int ledPin =  LED_BUILTIN;// the number of the LED pin
const int analogueOutLED = 2; // Analog out pin for external LED



// defines variables

long duration;
int distance;
int ledState = LOW;
int outputValue = 0; // For the external LED


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(ledPin, OUTPUT);



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
Serial.println(ledState);
}


