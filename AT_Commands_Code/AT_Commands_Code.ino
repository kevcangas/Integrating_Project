#include <SoftwareSerial.h>

SoftwareSerial D1(2,3);

void setup() {
  // put your setup code here, to run once:
  D1.begin(115200);
  Serial.begin(115200);

//  D1.println("AT+CWMODE=1");
//  delay(1000);
//  D1.println("AT+CWJAP=\"Oliva16\",\"00000000\"");
//  delay(10000);  
//  D1.println("AT+CIPMUX=1");
//  delay(1000);
//  D1.println("AT+CIPSERVER=1,80");
//  delay(1000);

}

void loop() {
  if (D1.available())
  {
    //Serial.write(D1.read());
    delay(1000);
    if(D1.find("+IPD,"))
    {
      int conexion = D1.read()-48;
      if(D1.find("tanque"))
      {
        int lectura = D1.read()-48;

        String pagina ="HOLA MUNDO!"; //"<!doctype html><html><head></head><body>";
        if (lectura==1)
        {
          pagina+="ESTA PRENDIDO!";//"<h1>LED=Encendido!</h1></body></html>";
        }
        else if (lectura==0)
        {
          pagina+="NO JALO );";//"<h1>LED=Apagado ):</h1></body></html>";
        }

        String enviar="AT+CIPSEND=";
        enviar+=conexion;
        enviar+=",";
        enviar+=pagina.length();
        D1.println(enviar);
        delay(1000);
        D1.println(pagina);
        delay(1000);

        String cerrar="AT+CIPCLOSE=";
        cerrar+=conexion;
        D1.println(cerrar);
        delay(2000);
         
      }  
    }
  }
  //if (Serial.available())
    //D1.write(Serial.read());

}
