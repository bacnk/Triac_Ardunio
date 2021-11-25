#include <DHT.h>
#include <TimerOne.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define Triac_Pin_1 3
//#define Triac_Pin_2 4
const int DHTPIN = 4;
const int  DHTTYPE =  DHT11;
DHT dht(DHTPIN, DHTTYPE);
float E1  ;
float E2 ;
float thoigian;

void Triac_Control1()
{
  
  delayMicroseconds(thoigian*1000);
  digitalWrite(Triac_Pin_1,HIGH);
  delayMicroseconds(10);
digitalWrite(Triac_Pin_1,LOW);
  
}
/*
void Triac_Control2()
{
  delayMicroseconds(E2*1000);
  digitalWrite(Triac_Pin_2,HIGH);
  delay(1);
digitalWrite(Triac_Pin_2,LOW);
}

  
void Fuzzy_Rule()
{
  float output1   ;

  if(t>=0 &&t <=17 && h>=0&&h<=35)
  {
   output1=10;
  }
  else if(17<=t&&t <=30 && 35<=h&& h<=47)
  {
   output1 =2;
  }
  thoigian = output1;
}
*/
void setup() {
  Serial.begin(9600);

 dht.begin();
  pinMode(Triac_Pin_1, OUTPUT);
  //pinMode(Triac_Pin_1, OUTPUT);
  
 attachInterrupt(0,Triac_Control1,RISING) ; // 1 o chan phat hiem diem 0 so 3, 0 o chan so phat hien diem khong so 2
  //attachInterrupt(0,Triac_Control2,RISING);
 Timer1.initialize(1000000);
Timer1.attachInterrupt(loop);
     
}
void loop() {
  
 float h = dht.readHumidity();    
  float t = dht.readTemperature(); 
  float output1   ;

  if(t <=17 && h<=35)
  {
   output1=10;
  }
  else if(17<=t&&t <=30 && 35<=h&& h<=47)
  {
   output1 =6;
  }
  thoigian = output1; 
}
