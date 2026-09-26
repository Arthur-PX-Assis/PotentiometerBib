#include "Potentiometer.h"

Potentiometer::Potentiometer(){
    pinMode(readPin, INPUT);
}

int Potentiometer::readOutput(){
    return analogRead(readPin);
}

float Potentiometer::readOutputTension{
    return readOutput() * 5.0 / 1023.0;
}

int Potentiometer::readOutputInInterval(int min, int max){
    return map(readOutput(), 0, 1023, min, max); // map(variável em questão, min atual, max atual, novo min, novo max)
}

void Potentiometer::writeInSerial(){

}