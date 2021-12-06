#include <Motor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Instancias a utilizar
Motor Motores(2,3,200);
LiquidCrystal_I2C lcd(0x3F,16,2);

//Variable PROVISIONAL para el código
bool controlM = 0;

void setup() {
  //Inicialización y conf de la pantalla
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

  pinMode(13,INPUT); //Señal para activar los motores (PROVISIONAL)
  
}

void loop() {

  if(controlM == 0 and digitalRead(13) == 1){
    lcd.setCursor(0,0);
    lcd.print("Desplegando...");
    controlM = 1;
    Motores.desplegar(250);
  }
  
  else if(controlM == 1 and digitalRead(13) == 1){
    lcd.setCursor(0,0);
    lcd.print("Contrayendo...");
    controlM = 0;
    Motores.contraer(250);
  }
  
}
