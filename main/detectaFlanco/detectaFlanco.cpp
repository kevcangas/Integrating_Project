#include "Arduino.h"
#include "detectaFlanco.h"

//detectaFlanco::detectaFlanco(){;}

short detectaFlanco::detectar(short pin) {
    //Devuelve 1 flanco ascendente, -1 flanco descendente y 0 si no hay nada
    static bool anterior_estado = digitalRead(pin);
    bool estado = digitalRead(pin);

    if (anterior_estado != estado) {
        if (estado == HIGH) {
            anterior_estado = estado;
            return 1;
        } 
        else {
            anterior_estado = estado;
            return -1;
        }
    }
    else {
        return 0;
    }
}