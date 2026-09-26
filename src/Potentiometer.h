#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

#define READ_PIN A0

class Potentiometer{
    private:
        byte readPin = READ_PIN;

    public:
        int readOutput();
        float readOutputTension();
        int readOutputInInterval(int min, int max);
        void writeInSeral();
};

#endif