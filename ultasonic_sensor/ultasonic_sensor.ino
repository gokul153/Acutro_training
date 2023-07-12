#define Trigg D1
#define Echo D4
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>


unsigned long myChannelNumber = 2210287;
const char * myWriteAPIKey = "F2LDSPQ6YP283VO1";
WiFiClient  client;
const char* ssid ="bgreen";
const char* password = "92221234";
int distance;
long duration;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(Trigg,OUTPUT);
  pinMode(Echo,INPUT);
  //pinMode(D0,OUTPUT);
  //pinMode(D7,OUTPUT);
  WiFi.mode(WIFI_STA);   
  
  ThingSpeak.begin(client);  
  
}

void loop() {
  // put your main code here, to run repeatedly:
   if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
   }
  Serial.println("\nConnected.");
  digitalWrite(Trigg,LOW);
  delay(2);
  digitalWrite(Trigg,HIGH);
  delay(10);
  digitalWrite(Trigg,LOW);
 duration=pulseIn(Echo,HIGH);
 Serial.println(duration);
distance= duration*0.034/2;
Serial.println("distance is");
 Serial.println(distance);
 int x = ThingSpeak.writeField(myChannelNumber, 1,distance, myWriteAPIKey);
    //uncomment if you want to get temperature in Fahrenheit
    //int x = ThingSpeak.writeField(myChannelNumber, 1, temperatureF, myWriteAPIKey);

    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
delay(1000);
 
//  if(distance<30 || distance>100){
//    Serial.println("no object is found nearby");
//    digitalWrite(0,HIGH);
//    delay(1000);
//     digitalWrite(0,LOW);
//     digitalWrite(7,LOW); 

//  }
//  else if(distance>30||distance<100){
//    digitalWrite(7,HIGH); 
//    delay(2000);
//     digitalWrite(7,LOW);
//    digitalWrite(0,LOW); 

//  }
//  else{
//     digitalWrite(7,LOW); 
//          digitalWrite(0,LOW);
//     }  
 
 
}
