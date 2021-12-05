#include "Arduino.h"
#include "Motor.h"

Motor::Motor(short dirPin,short stepPin,short steps){
    m_dirPin = dirPin;
    m_stepPin = stepPin;
    m_steps = steps;
}

void Motor::desplegar(int speed){
    //Serial.print("Desplegando...");
    digitalWrite(m_dirPin,HIGH);
    for(int i = 0; i < m_steps; i++){
        digitalWrite(m_stepPin, HIGH);
        delayMicroseconds(speed);
        digitalWrite(m_stepPin, LOW);
        delayMicroseconds(speed);
    }
}

void Motor::contraer(int speed){
    //Serial.print("Contrayendo...");
    digitalWrite(m_dirPin,LOW);
    for(int i = 0; i < m_steps; i++){
        digitalWrite(m_stepPin, HIGH);
        delayMicroseconds(speed);
        digitalWrite(m_stepPin, LOW);
        delayMicroseconds(speed);
    }
}