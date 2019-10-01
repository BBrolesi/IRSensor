#include "sensor.h"
#include <Arduino.h>

Sensor::Sensor(){
    this->valorMaximo = 0;
    this->valorMinimo = 4095;
    this->sensibilidade = 0.5;
    this->peso = 0;
    this->erro = 0;
    this->limiarAD = 3500;
}

void Sensor::setPinSensor(int pinSensor)
{
    this->pinSensor = pinSensor;
}

void Sensor::calibrar(){
    int valor = analogRead(this->pinSensor);
    if(valor > this->valorMaximo)
    {
        this->valorMaximo = valor;
    }
    if(valor < this->valorMinimo)
    {
        this->valorMinimo = valor;
    }

    this->limiarAD = (this->sensibilidade) * this->valorMinimo + (1 - this->sensibilidade) * this->valorMaximo;

}

int Sensor::getValorAnalogicoSensor(){
    return analogRead(this->pinSensor);
}

int Sensor::getValorDigitalSensor(){
    return this->valorDigitalSensor;
}

void Sensor::setValorDigitalSensor()
{
    if(analogRead(this->pinSensor) > this->limiarAD)
    {
        this->valorDigitalSensor = 1;
    }
    else
    {
        this->valorDigitalSensor = 0;
    }
}

float Sensor::getPeso(){
    return this->peso;
}

void Sensor::setPeso(float peso){
    this->peso = peso;
}

int Sensor::getErro()
{
    return this->erro;
}

void Sensor::setErro(int erro)
{
    this->erro = erro;
}