#include <Arduino.h>
#include <Servo.h> 
#include <Adafruit_INA219.h>
#include <Wire.h>

// ---------------- Pin Definitions -------------------- //
#define LED 13 
#define Servo1_pin 2
#define Servo2_pin 3
#define Servo3_pin 4
#define Servo4_pin 5

#define Pressure_voltage A0


// ---------------- Objects -------------------- //
Adafruit_INA219 ina219_Servo1;
Adafruit_INA219 ina219_Servo2(0x41);
Adafruit_INA219 ina219_Servo3(0x42);

Servo servo1;  // create servo1 object to control a servo1
Servo servo2;
Servo servo3;
Servo servo4; 
               
// ---------------- Global variables -------------------- //
float Servo1_current_mA = 0;
float Servo2_current_mA = 0;
float Servo3_current_mA = 0;

int pos = 0;    // variable to store the servo position 
 
void setup() { 
  // ----------------
  pinMode(LED, OUTPUT);

  // ---------------- Init servos -------------------- //
  servo1.attach(Servo1_pin, 600, 2400);  // attaches the servo on pin 20
  servo2.attach(Servo2_pin, 600, 2400);  // attaches the servo on pin 21
  servo3.attach(Servo3_pin, 600, 2400);  // attaches the servo on pin 22
  servo4.attach(Servo4_pin, 600, 2400);  // attaches the servo on pin 23 
  
  // ---------------- Init current sensors -------------------- //
  ina219_Servo1.begin();
  ina219_Servo2.begin();
  ina219_Servo3.begin();
} 
 
 
void loop() { 
  digitalWrite(LED, HIGH);

  Servo1_current_mA = ina219_Servo1.getCurrent_mA();
  Servo2_current_mA = ina219_Servo2.getCurrent_mA();
  Servo3_current_mA = ina219_Servo3.getCurrent_mA();

  servo1.write(0);  // tell servo to go to a particular angle
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  for(pos = 0; pos < 180; pos += 1)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    delay(30);                       // waits 15ms for the servo to reach the position 
  } 
  digitalWrite(LED, LOW);
  
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    delay(30);                       // waits 15ms for the servo to reach the position 
  } 
}