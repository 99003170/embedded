#include <SPI.h>

volatile boolean received;
volatile uint16_t  Slavereceived, Slavereceived2;
int count=0;
int count1=0;
int temp=0;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                  
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                      
  received = false;
  SPI.attachInterrupt();
  Serial.print("GETTING READY...........");
  delay(2000);
  Serial.print("SENSOR READY");  
               
}


ISR (SPI_STC_vect)                        
{
    Slavereceived = SPDR;            
    received = true;
}

 

void loop()
{
  if(received)                          
  {  
      if(Slavereceived != 0)
      {
      received = false;
      count++;  
      if(count>=(temp+12))
      {
        count1++;
        Serial.print("person is Detected ");
        Serial.println(count1);
        temp=count;
      }

      delay(100);
      }
      else
      {
      received = false;    
      Serial.println("No person is detected");
      delay(100);
      }
  }
}

