#include <SoftwareSerial.h>

SoftwareSerial D1(2,3);

void setup() {
  // put your setup code here, to run once:
  D1.begin(9600);
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  D1.println("AT+CWMODE=1");
  delay(100);
//  D1.println("AT+CWJAP=\"Oliva16\",\"00000000\"");
//  delay(10000);  
  D1.println("AT+CIPMUX=1");
  delay(100);
  D1.println("AT+CIPSERVER=1,80");
  delay(100);

}

void loop() {
  if (D1.available())
  {
    //Serial.write(D1.read());
    delay(250);
    String pagina;
    if(D1.find("+IPD,"))
    {
      int conexion = D1.read()-48;
      if(D1.find("?data="))
      {
        int lectura = D1.read()-48;
        if(!lectura)digitalWrite(LED_BUILTIN, HIGH);
        else if (lectura) digitalWrite(LED_BUILTIN, LOW);
        
      } 
//      else {
//        pagina+="Sigo en la pagina principal";
//      }
      pagina="<html><head><title>Rainwater Collector</title></head><body><h2>Deploy/Contract</h2><button onClick=location.href='./?data=0'>ON</button><button onClick=location.href='./?data=1'>OFF</button><h2>Tank capacity with water</h2><strong>82%</strong></body></html>"; //"<!doctype html><html><head></head><body>";
      String enviar="AT+CIPSEND=";
      enviar+=conexion;
      enviar+=",";
      enviar+=pagina.length();
      D1.println(enviar);
      delay(100);
      D1.println(pagina);
      delay(100);

      String cerrar="AT+CIPCLOSE=";
      cerrar+=conexion;
      D1.println(cerrar);
      delay(300);
    }
  }
  
  //if (Serial.available())
    //D1.write(Serial.read());

}
