
  const  int acc = 255;                      
  const  int turn_acc = 255;     
  const  int t_p_acc = 255;
  const  int obstacle = 12;

  const int trigPin = 11;
  const int echoPin = 12;

  const int m1      = 3;  
  const int m1_2      = 4; 
  const int m1_speed  = 5;
  const int m2      = 7; 
  const int m2_2      = 8; 
  const int m2_speed  = 6;

  const int left_ir =9;
  const int right_ir =10;

  int turnspeed;
  int left_ir_val;
  int right_ir_val;

  long duration;
  int distance;

void setup() 
{
  pinMode(m1, OUTPUT);
  pinMode(m1_2, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m2_2, OUTPUT);
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
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);


left_ir_val = digitalRead(left_ir);
right_ir_val = digitalRead(right_ir);



if(right_ir_val == HIGH && left_ir_val == LOW)
{
  Serial.println("turning right");

  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,LOW);
  digitalWrite(m2_2,HIGH);

  analogWrite (m1_speed, acc);
  analogWrite (m2_speed, turn_acc);
  
  }
if(right_ir_val == LOW && left_ir_val == HIGH)
{
  Serial.println("turning left");
  
  digitalWrite (m1,HIGH);
  digitalWrite(m1_2,LOW);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);

  analogWrite (m1_speed, turn_acc);
  analogWrite (m2_speed, acc);

  delay(10);
  }

if(right_ir_val == LOW && left_ir_val == LOW)
{
  Serial.println("going forward");

  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);

  analogWrite (m1_speed, acc);
  analogWrite (m2_speed, acc);

  delay(10);
  
  }

if(right_ir_val == HIGH && left_ir_val == HIGH)
{ 
  Serial.println("stop");
  
  analogWrite (m1_speed, 0);
  analogWrite (m2_speed, 0);
  }

 if(distance < obstacle)
 {

  digitalWrite (m1,HIGH);
  digitalWrite(m1_2,LOW);                       
  digitalWrite (m2,LOW);
  digitalWrite(m2_2,HIGH);
  delay(250);
  analogWrite (m1_speed, 0);
  analogWrite (m2_speed, 0);
  delay(500);
  digitalWrite (m1,HIGH);
  digitalWrite(m1_2,LOW);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);

  analogWrite (m1_speed, t_p_acc);
  analogWrite (m2_speed, t_p_acc);
  delay(900);


  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);

  analogWrite (m1_speed, t_p_acc);
  analogWrite (m2_speed, t_p_acc);
  delay(800);

  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,LOW);
  digitalWrite(m2_2,HIGH);
  delay(900);

  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);

  delay(700);

   digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,LOW);
  digitalWrite(m2_2,HIGH);
  delay(650);

  digitalWrite (m1,LOW);
  digitalWrite(m1_2,HIGH);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);
}

  digitalWrite (m1,HIGH);
  digitalWrite(m1_2,LOW);                       
  digitalWrite (m2,LOW);
  digitalWrite(m2_2,HIGH);
  delay(100);
  
  digitalWrite (m1,HIGH);
  digitalWrite(m1_2,LOW);                       
  digitalWrite (m2,HIGH);
  digitalWrite(m2_2,LOW);
  delay (500);
}          
