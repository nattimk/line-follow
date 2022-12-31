  int vSpeed = 150;        // MAX 255
  int turn_speed = 170;    // MAX 255 
  int turn_delay = 0;
  int stop_speed = 0;
  
//L293 Connection   
  const int motorA1      = 7; //RIGHT 
  const int motorA2      = 6; //RIGHT
  const int motorAspeed  = 5;
  const int motorB1      = 9; //LEFT
  const int motorB2      = 8; //LEFT
  const int motorBspeed  = 10;

//Sensor Connection
  const int left_sensor_pin =A1; //
  const int right_sensor_pin =A0; //

  
  
  int left_sensor_state;
  int right_sensor_state;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
  pinMode(motorBspeed, OUTPUT);

  Serial.begin(9600);

  delay(3000);
  
}

void loop() {
  

  // LADYBOT


left_sensor_state = analogRead(left_sensor_pin);
right_sensor_state = analogRead(right_sensor_pin);

if(right_sensor_state > 500 && left_sensor_state < 500)
// the right sensor is over a black line, turn right till both sensors are < 500 (over white surface)
{
  Serial.println("turning right");

  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
  
  }
if(right_sensor_state < 500 && left_sensor_state > 500)
// the left IR sensor is over a black line, turn left till both sensors are < 500 (over white surface)
{
  Serial.println("turning left");
  
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state < 500 && left_sensor_state < 500)
{
  Serial.println("going forward");

  digitalWrite (motorA1,LOW);  
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  
  }

if(right_sensor_state > 500 && left_sensor_state > 500)
{ 
  Serial.println("stop");
  digitalWrite (motorA1,LOW);  
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
  delay(10);
  
  }

 
}
