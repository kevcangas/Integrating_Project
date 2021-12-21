#include <Motor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <ESP8266.h>
#include <wifiSimp.h>
#include <SoftwareSerial.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 400

//Instancias a utilizar
Motor Motores(2,3,200);
LiquidCrystal_I2C lcd(0x3F,16,2);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


//Char para internet
const char* SSID = "myssid";
const char* PASSWORD = "mypasword";

SoftwareSerial softSerial(2, 3); // RX, TX
ESP8266 wifi(softSerial);

wifiSimp server;

//Variable PROVISIONAL para el código
bool controlM = 0;

int llenadoTan(int distancia){
  int alturaTan = 250; //Medición en centimetros
  int diametro = 10;
  int vTotal = (3.1416/4*diametro*diametro)*alturaTan;
  int vReal = (3.1416/4*diametro*diametro)*(alturaTan-distancia);
  return vReal/vTotal*100;
}

void setup() {
  //Inicialización y conf de la pantalla
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();

  pinMode(13,INPUT); //Señal para activar los motores (PROVISIONAL)
  
}

void loop() {
  String EdoMot;  
//Activación de motores
  if(controlM == 0 and digitalRead(13) == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Desplegando...");
    controlM = 1;
    Motores.desplegar(250);
    while(digitalRead(13) == 1);
    lcd.clear();
  }
  
  else if(controlM == 1 and digitalRead(13) == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Contrayendo...");
    controlM = 0;
    Motores.contraer(250);
    while(digitalRead(13) == 1);
    lcd.clear();
  }

//Lectura del llenado del tanque
  int us = sonar.ping_median();
  lcd.setCursor(0,0);
  lcd.print("Llenado: ");
  String porTan = String(llenadoTan(us/US_ROUNDTRIP_CM));
  lcd.print(porTan); 
  lcd.clear();
}
