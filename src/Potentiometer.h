#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

#define READ_PIN A0

class Potentiometer{
    private:
        byte readPin = READ_PIN; // Pino para saída do potênciometro

    public:
        Potentiometer(); // Construtor
        int readOutput(); // Lê a saída diretamente
        float readOutputTension(); // Converte a saída para tensão (0V-5V)
        int readOutputInInterval(int min, int max); // Converte a saída para um intervalo personalizado
        void writeInSeral(); // Escreve no serial
};

#endif