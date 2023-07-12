#include <Keypad.h>
#include<stdio.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char num1;
int Number=0;
int flag=0;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//byte rowPins[ROWS] = {D3, D2, D1, D0}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {D7, D6, D5, D4}; //connect to the column pinouts of the keypad
byte rowPins[ROWS] = {D7, D6, D5, D4}; //connect to the column pinouts of the keypad
byte colPins[COLS] = {D3, D2, D1, D0}; 
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS,COLS);

#include <Servo.h>

Servo s1;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup(){
  Serial.begin(9600);
   s1.attach(D8);  
  //ad the key
  Serial.println("ENter the value");
  delay(3000);// Re
}
  
void loop(){
  char key = keypad.getKey();
  
  // Print if key pressed
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
  /*   while(flag!='1'){
  if(key=='1'){
    num1+= key;
  }
   if(key=='2'){
    num1+= key;
  }
   if(key=='3'){
    num1+= key;
  }*/
  if(key=='A'){
    Serial.print("no is ");
    Serial.println(Number);
    flag=1;
  }
  if(key=='D'){
    Number=0;
    Serial.print("no updated ");
    Serial.println(Number);
    flag=0;
  }
  
    Serial.print("Key Pressed : ");
    Serial.println(key);
    if(Number==123 && flag==1){
        Serial.println("Access Granted");
  
  s1.write(0);  
   delay(3000);  
   s1.write(90);  
   delay(3000);  
   s1.write(180);  
   delay(1000);   
   Number=0;
   flag=0;
   Serial.println("closed Enter key again");
  
    }else if(flag==1){
      Serial.println("Wrong key Try again");
      flag=0;
      Number=0;
    }
  }
}