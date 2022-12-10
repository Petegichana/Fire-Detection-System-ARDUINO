#include <Stepper.h>

#include <Adafruit_LiquidCrystal.h>

#include <Adafruit_LEDBackpack.h>

#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup()
{
  lcd.begin(16,2);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd.clear();
}

void loop()
{
  int a=analogRead(A0);
  Serial.println(a);
  Serial.println();
  delay(1000);
  float b=0;
  float celsius=0;
  float voltage=0;
  b=analogRead(A1);
  voltage=b*5000/1024;
  voltage=voltage-500;
  celsius=voltage/10;
  Serial.println(celsius);
  Serial.println();
  if(celsius>35){
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  lcd.setCursor(0,1);
  lcd.print("TEMP IS ");
  lcd.print(celsius);
  delay(1000);
  }
  else{
  digitalWrite(12,LOW);
  digitalWrite(12,LOW);
  lcd.setCursor(0,1);
  lcd.print("TEMP IS ");
  lcd.print(celsius);
  delay(1000);
  }
 if(a > 500){
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  lcd.display();
  lcd.setCursor(0,0); 
  lcd.print("Smoke detected");
  }
  else{
  digitalWrite(8,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);
  lcd.display();
  lcd.setCursor(0,0); 
  lcd.print("Safe           ");
  } 
}