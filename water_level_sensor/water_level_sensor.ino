#define water A0
int level=0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(4,OUTPUT);
 pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  level= analogRead(A0);
  int rand =random(300);
  Serial.println(rand);
  analogReference(EXTERNAL);
  Serial.println(level);
  delay(1000);
  ///analogReadResolution(10);
  Serial.print("ADC 10-bit (default) : ");
  Serial.print(analogRead(A0));

 

}
