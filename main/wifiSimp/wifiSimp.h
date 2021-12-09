#ifndef wifiSimp_h
#define wifiSimp_h

#include "Arduino.h"
#include "ESP8266.h"

class wifiSimp{
    public:
        wifiSimp(void){;}
        void init(ESP8266 wifi,char* SSID,char* PASSWORD);
        //void wifiWrite(char* A);
        void sendServer(ESP8266 wifi);
};
#endif