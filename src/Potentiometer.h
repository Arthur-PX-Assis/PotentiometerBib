#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer{
    private:
        byte readPin; // Pino para saída do potenciômetro

    public:
        Potentiometer(byte readPin); // Construtor

        // Leitura
        int readOutput(); // Lê a saída diretamente
        float readOutputTension(); // Converte a saída para tensão (0V-5V)
        int readOutputInInterval(int min, int max); // Converte a saída para um intervalo personalizado

        // Escrita
        void writeOutputInSerial();
        void writeTensionInSerial();
        void writeIntervalInSerial(int min, int max);
};

#endif