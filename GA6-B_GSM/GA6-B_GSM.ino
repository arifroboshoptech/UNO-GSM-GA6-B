#include <SoftwareSerial.h>


#define GSM_RX  2  
#define GSM_TX  3  

SoftwareSerial sim(GSM_RX, GSM_TX);  //


String number = "+60183712204"; 




void setup() {
  Serial.begin(115200); 
 
  Serial.println("System Started...");
  sim.begin(115200);
  delay(1000);
  
 Serial.println("Communicating GSM/GPS.....");

call(); 
delay(8000);
sms();   
}

void loop() {
 
 
} 



void sms()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    
  delay(1000);
  Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); 
  delay(1000);
  String SMS = "Sample SMS is sending";   
  
   sim.println(SMS);
   
   delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
 
}

void call() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
 
  
}
