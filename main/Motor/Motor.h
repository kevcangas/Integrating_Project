#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
    public:
        Motor(short dirPin,short stepPin,short steps);
        void desplegar(int speed);
        void contraer(int speed);
        short m_dirPin;
        short m_stepPin;
        short m_steps;
};
#endif