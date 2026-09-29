/*
 Exemplo de uso da biblioteca Potentiometer
  
  Este código mostra como inicializar a classe Potentiometer
  e utilizar suas funções para exibir os valores no monitor serial 
  de forma bruta, convertida para tensão e mapeada em um intervalo
*/

#include <Potentiometer.h>

// Instancia o objeto do potenciômetro passando o pino que está conectado
Potentiometer meuPotenciometro(A0);

void setup() {
  // Inicializa a comunicacao serial a 9600 bps (padrão)
  Serial.begin(9600);
  While (!Serial);
 
  Serial.println("Demonstracao do uso da biblioteca");
  Serial.println("----------------------------------------");
}

void loop() {
  // Exibe o valor bruto lido pela porta analógica (0 a 1023)
  meuPotenciometro.writeOutputInSerial();

  // Exibe a conversão direta para tensao em volts (0V a 5V)
  meuPotenciometro.writeTensionInSerial();

  // Exibe o valor mapeado para uma escala personalizada
  meuPotenciometro.writeIntervalInSerial(0, 100);

  // Pula uma linha para melhorar a leitura na próxima iteração
  Serial.println();
  
  // Aguarda meio segundo antes da próxima leitura
  delay(500); 
}
