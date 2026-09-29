#include "Potentiometer.h"

Potentiometer::Potentiometer(byte readPin){
    this->readPin = readPin; // Sem uso de define ou const para caso de uso de mais de um potenciômetro
    pinMode(this->readPin, INPUT);
}

int Potentiometer::readOutput(){
    return analogRead(readPin);
}

float Potentiometer::readOutputTension(){
    return readOutput() * 5.0 / 1023.0;
}

int Potentiometer::readOutputInInterval(int min, int max){
    if (min >= max) return -1;

    return map(readOutput(), 0, 1023, min, max); // map(variável em questão, min atual, max atual, novo min, novo max)
}

void Potentiometer::writeOutputInSerial() {
    Serial.print("Bruto: ");
    Serial.println(readOutput());
}

void Potentiometer::writeTensionInSerial() {
    Serial.print("Tensao: ");
    Serial.print(readOutputTension());
    Serial.println("V");
}

void Potentiometer::writeIntervalInSerial(int min, int max) {
    Serial.print("Mapeado (");
    Serial.print(min);
    Serial.print("-");
    Serial.print(max);
    Serial.print("): ");

    int resultInterval = readOutputInInterval(min, max);

    if (resultInterval != -1) Serial.println(resultInterval);
    else Serial.println("ERRO: 'min' deve ser menor que 'max'!");
}