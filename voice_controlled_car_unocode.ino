#include <SoftwareSerial.h>
int RX_pin =2;
int TX_pin =3;
SoftwareSerial BTserial(RX_pin, TX_pin);
String BTdata;
String UNOdata;
const int trigPin = 7;
const int echoPin = 8;
int in1 = 9; //For motor 1
int in2 = 10;
int in3 = 11; //For motor 2
int in4 =12;
int duration;
int distance;


void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(in1,  OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3,  OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
}

void loop() {

  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  //Serial.println(distance);

  
  
  
  
  if(BTserial.available())
  {
    BTdata = BTserial.readString();
    Serial.println(BTdata);
    BTserial.print("You sended me:");
    BTserial.println(BTdata);
    
   }

   if(Serial.available()) {
    UNOdata = Serial.readString();
    BTserial.println(UNOdata);
    }

  if(BTdata == "ahead" or BTdata == "front" or BTdata == "move ahead"){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }

  if(BTdata == "go back" or BTdata == "move back" or BTdata == "back"){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    }

   if(BTdata == "turn right" or BTdata == "right" or BTdata == "move right"){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(3000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    }
  if(BTdata == "turn left" or BTdata == "left" or BTdata == "move left"){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(3000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    }

   if(BTdata == "stop"){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    }

    if(distance<=5){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    }


//Serial.println(BTdata);
}

//code is officially written by NAMAN SHARMA
