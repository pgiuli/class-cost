#include <Wire.h>      
#include <LCD.h>      
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


using namespace std;


unsigned long milis_run;
unsigned long milis_stopped;

unsigned int number_of_digits = 0;

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
  lcd.print("- Preu classe v1.2 -");

  lcd.setCursor(1, 1); 
  lcd.print("Cost de la classe");


}




void loop()
{
byte contant = digitalRead(switch_pin);

  
  if (contant == LOW) {
    milis_run = millis() - milis_stopped;
  
    lcd.setCursor(6, 2);

    int centims_total = round(milis_run/3600);
    int centims = centims_total % 100;



    lcd.print(centims_total / 100);
    lcd.print(".");

    if (centims < 10){
      lcd.print("0");
    }
    lcd.print(centims);
    lcd.print("  EUR");

    lcd.setCursor(0, 3);
    lcd.print("Comptant...  ");

  }

  else {
  
    milis_stopped = millis() - milis_run;
  

    lcd.setCursor(6, 2);

    int centims_total = round(milis_run/3600);
    int centims = centims_total % 100;



    lcd.print(centims_total / 100);
    lcd.print(".");
        if (centims < 10){
      lcd.print("0");
    }
    lcd.print(centims);
    lcd.print("  EUR");
    
    lcd.setCursor(0, 3);
    lcd.print("Aturat...  ");
  }


delay(10);

}