#define trigPin1 3
#define echoPin1 4
#define trigPin2 5
#define echoPin2 6
#define trigPin3 7
#define echoPin3 8
#define trigPin4 9
#define echoPin4 10

int count1;
int count2;
int var1=false;
int var2=false;

#define light1 11
#define light2 12
#define light3 13
#define light4 14


void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(light4, OUTPUT);
}

void loop()
 {
  //____________This is for in detection___________//
      long duration1, distance1;
     digitalWrite(trigPin1, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin1, HIGH);
     delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1/74/2;

   if (distance1 <= 20 and var2==false)
   {
       var1=true;
    }
    
    long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2/74/2;
  
   if(distance2<=20 and var1==true)
   {
          count1++;
          var1=false;
          digitalWrite(light1,HIGH);
           Serial.println("Person in");
            Serial.println(count1);
     delay (1000);
   }
   
   
   
//______This is for out detection____//

   digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2/74/2;
  
  
  if(var1==false and distance2<=20)
  {
        var2=true;
    }
     digitalWrite(trigPin1, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin1, HIGH);
     delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1/74/2;
    
    if(var2==true and distance1<=20)
    {
            count1--;
            var2=false;   
            Serial.println("Person out");
            Serial.println(count1);
      delay(1000);
    }
    
       if(count1==0)
       {
           digitalWrite(light1,LOW);
        } 
}