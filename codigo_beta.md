#include <Servo.h>
const float BASE = 0.4887585532746823069403714565; //Base de conversão para Graus Celsius ((5/1023) * 100)
Servo valvulaRese; //declara a função do servo

void setup() {
  Serial.begin(9600);   //configura a comunicação serial com o pc
  valvulaRese.attach(3); //declara a porta pwm a ser utilizada pelo servo
}
void loop(){
    float temperatura = analogRead(A0)*BASE; //faz o calculo da temperatura da temperatura de acordo com a base
    delay(1000);
    Serial.print("Temperatura: ");
    Serial.println(temperatura); //imprime a temperatura na comunicação serial com o pc
   
    //Calculo para determinar a posição do servo de acordo a variação da temperatura
    float calc = temperatura - 20;
    float posi = calc*18;  

    valvulaRese.write(posi); //muda a posição do servo
    Serial.print("Graus: "); // imprime a posição do servo
    Serial.println(posi);

  
}
