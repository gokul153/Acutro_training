/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Number=0,flag=0;
 String input;
 #include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 10, A5, A4}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(20,4);
  pinMode(A3, OUTPUT);
   pinMode(1, OUTPUT);

  // Print a message to the LCD.
  lcd.print("hello, world!");
 ///  Serial.print("Enter the string to be displayed");
  //Serial.setTimeout(20);
 // input=Serial.readStringUntil("\n");

  //Serial.println(input);
 // delay(3000);
  lcd.setCursor(0, 1);
 // lcd.print(input);
 // Serial.println("Enter the string to be displayed");
 // lcd.clear();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 // lcd.clear();
// lcd.clear();.
  lcd.setCursor(0,1);
char key = keypad.getKey();// Read the key
delay(1000);
  lcd.setCursor(0,2);
  // Print if key pressed
lcd.print("enter number");
lcd.setCursor(0,4);
lcd.print(Number);
 if (key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print(key);
   // delay(2000);
  }
  if (key){
    if (key == '1') //If Button 1 is pressed

    {Serial.println ("Button 1"); 

    if (Number==0)

    Number=1;

    else

    Number = (Number*10) + 1; //Pressed twice

    }

    

     if (key == '4') //If Button 4 is pressed

    {Serial.println ("Button 4"); 

    if (Number==0)

    Number=4;

    else

    Number = (Number*10) + 4; //Pressed twice

    }

    

     if (key == '7') //If Button 7 is pressed

    {Serial.println ("Button 7");

    if (Number==0)

    Number=7;

    else

    Number = (Number*10) + 7; //Pressed twice

    } 

  


    if (key == '0')

    {Serial.println ("Button 0"); //Button 0 is Pressed

    if (Number==0)

    Number=0;

    else

    Number = (Number*10) + 0; //Pressed twice

    }

    

     if (key == '2') //Button 2 is Pressed

    {Serial.println ("Button 2"); 

     if (Number==0)

    Number=2;

    else

    Number = (Number*10) + 2; //Pressed twice

    }

    

     if (key == '5')

    {Serial.println ("Button 5"); 

     if (Number==0)

    Number=5;

    else

    Number = (Number*10) + 5; //Pressed twice

    }

    

     if (key == '8')

    {Serial.println ("Button 8"); 

     if (Number==0)

    Number=8;

    else

    Number = (Number*10) + 8; //Pressed twice

    }   
      if (key == '3')

    {Serial.println ("Button 3"); 

     if (Number==0)

    Number=3;

    else

    Number = (Number*10) + 3; //Pressed twice

    }

    

     if (key == '6')

    {Serial.println ("Button 6"); 

    if (Number==0)

    Number=6;

    else

    Number = (Number*10) + 6; //Pressed twice

    }

    

     if (key == '9')

    {Serial.println ("Button 9");

    if (Number==0)

    Number=9;

    else

    Number = (Number*10) + 9; //Pressed twice

    }  
     if(Number==123){
      lcd.print("Access Granted");
      Number=0;
      digitalWrite(A3,HIGH);
      delay(4000);
      digitalWrite(A3,LOW);
      lcd.clear();
    }
  
  if(key=='A'){
    Serial.print("no is ");
    Serial.println(Number);
   // lcd.print(Number);
    flag=1;
 //   delay(1000);
    if(Number==123){
      lcd.print("Access Granted");
      digitalWrite(A3,HIGH);
      delay(4000);
      digitalWrite(A3,LOW);
      lcd.clear();
    }
    else if(Number==150){
      lcd.print("Gokul welcome");
      delay(2500);
      lcd.clear();
    }
    else if(Number==200){
      lcd.print("Bhagavath welcome");
      delay(3000);
      lcd.clear();
    }
    else{
      lcd.print("Access not Grant");
      Number=0;
      delay(4000);
      lcd.clear();
      lcd.print("Enter new Number");
      delay(2000);
      lcd.clear();
    }
  }
  if(key=='D'){
    Number=0;
    Serial.print("no updated ");
    Serial.println(Number);
    flag=0;
    lcd.clear();
    lcd.print("Number Cleared");
    delay(1000);
  }
  }
  lcd.setCursor(0, 3);
/* while(Serial.available())
 {
 // Serial.print("Enter the string to be displayed");
  Serial.setTimeout(20);
  input=Serial.readStringUntil("\n");

  Serial.println(input);
  //delay(3000);
  
  lcd.print(input);
  Serial.println("Enter the string to be displayed");
  delay(2000);
  
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  lcd.setCursor(0,2);
  //lcd.print(input);
  delay(3000);
 }
 if(!Serial.available()){
   delay(10000);
 }*/
}

