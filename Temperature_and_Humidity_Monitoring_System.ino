#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // RX, TX

#include <LiquidCrystal.h> 
#include "dht.h"
#define dataPin A0
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
  
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
  
  

 bt.print(temp); //send distance to MIT App
 bt.print(";");
 bt.print(hum); //send distance to MIT App 
 bt.println(";");
  
  delay(1000);
}
