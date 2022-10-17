#include <Wire.h>      
#include <LCD.h>      
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


unsigned long temps;

unsigned long milis_run;
unsigned long milis_stopped;

int switch_pin = 4;
int button_pin = 6;

int counting = 0;


void setup()
{
Serial.begin(9600);

  pinMode(switch_pin, INPUT);
  pinMode(button_pin, INPUT);


  milis_run = 0;
  milis_stopped = 0;



  lcd.begin(20, 4);
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("- Preu classe v1.0 -");




}




void loop()
{
byte contant = digitalRead(switch_pin);

  
  if (contant == LOW) {
    milis_run = millis() - milis_stopped;
    




 
  //temps = round(millis()/1000);
  
  

  lcd.setCursor(5, 1); 
  lcd.print(round(milis_run/1000)); 

  lcd.setCursor(0, 3);
  lcd.print("Comptant  ");

  }

  else {
  
    milis_stopped = millis() - milis_run;
  //Serial.println("Button is not pressed");
  
  
  lcd.setCursor(5, 1); 
  lcd.print(round(milis_run/1000));  
  
  lcd.setCursor(0, 3);
  lcd.print("Aturat  ");
  }

//delay(100);

}