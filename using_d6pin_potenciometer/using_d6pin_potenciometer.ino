#include <LiquidCrystal.h> 
#include <stdio.h>
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
 #include "uRTCLib.h"
// uRTCLib rtc;
uRTCLib rtc(0x68);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String time;
 void setup()
 {
   Serial.begin(9600);
   URTCLIB_WIRE.begin();
   // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
   rtc.set(0,45,16,1,26,6,23);
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
   String strh;
    rtc.refresh();
  lcd.clear();
  Serial.print("Current Date & Time: ");
  Serial.print(rtc.year());
  Serial.print('/');
  Serial.print(rtc.month());
  Serial.print('/');
  Serial.print(rtc.day());
  Serial.println("Time details are as follows \n");
  delay(1000);
  Serial.print(rtc.hour());
   Serial.print(":");
  Serial.print(rtc.minute());
   Serial.print(":");
  Serial.println(rtc.second());
  lcd.print(rtc.hour());
  lcd.print(":");
  lcd.print(rtc.minute());
  lcd.print(":");
  lcd.print(rtc.second());
  int hour =rtc.hour();
  //sprintf(strh, "%d", rtc.hour());
  //tostring(strh, rtc.hour);
  //time = tostring(rtc.hour())+":"+tostring(rtc.minute())+":"+tostring(rtc.second());
  //date =rtc.
  lcd.setCursor(0,0);
 // lcd.print(time);
  lcd.setCursor(0,1);
  //lcd.print(date);
  Serial.print("Temperature: ");
  Serial.print(rtc.temp()  / 100);
  Serial.print("\xC2\xB0");   //shows degrees character
  Serial.println("C");
  delay(3000);
  /* analogWrite(6,75);
     lcd.setCursor(0, 0);
     lcd.print("Contast to 75");
     delay(3000);
     lcd.clear();
     analogWrite(6,80);
      lcd.print("Contast to 80");
     delay(3000);
     lcd.clear();
        analogWrite(6,50);
     lcd.print("Contast to 50");
     delay(3000);
     lcd.clear();
    lcd.setCursor(0, 1);
     lcd.print("Display");*/
     delay(3000);
 }
