#ifndef sensor_h
#define sensor_h

class Sensor
{
private:
    int pinSensor; //Pino responsável pela leitura do Sensor
    int valorAnalogicoSensor; //Valor lido pelo sensor
    int valorDigitalSensor; //Valor convertido para digital
    float peso; //Peso do erro de cada sensor, isso irá influenciar no algoritimo de PID
    int erro; //Erro para cada sensor
    float sensibilidade; //sensibilidade para correção de leitura de cada sensor
    int valorMaximo; //Valor maximo possivel de leitura do sensor
    int valorMinimo; //Valor minimo possivel de leitura do sensor
    int limiarAD; //Valor de limiar para se tornar digital

public:
    Sensor();
    void setPinSensor(int pinSensor);
    void calibrar(); //Função responsável por calibrar os sensores a cada inicialização
    int getValorAnalogicoSensor(); //Retorna o valor analogico lido pelo sensor
    int getValorDigitalSensor(); //Converte o valor analogico para digital e o retorna
    void setValorDigitalSensor();
    float getPeso(); //Retorna o valor do peso do sensor
    void setPeso(float peso); //Define o valor do peso do sensor
    int getErro(); //Retorna o erro do sensor
    void setErro(int erro); //Define o erro do sensor

};

#endif