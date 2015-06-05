#include <Servo.h>
Servo servo;

int led1 = 7;
int led2= 8;

void setup() {
  servo.attach(10);
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
   
}
int posi = 0;   //Posição geral do Servo
void loop() {
  int sensor1 = 0;
  int sensor2 = analogRead(A1); //Lendo o sensor externo
  
  if(sensor2 > 10){ //Verifica se há luz externamente
      
      sensor1 = analogRead(A0); //Verifica o sensor interno
      
      if(sensor2 < 800){ //Verifica se há pouca luminosidade internamente
        int cont = 0;
        
        while(sensor2 < 800){ //Enquanto a luminosidade for baixa
          
          if(posi < 180){ //Verifica se o servo já chegou na posição final, se não, ele move o servo até o ponto mais luminoso
            int exec = posi + 1; //Acrescenta um grau na posição atual do servo
            servo.write(exec);  
            posi = exec; //Salva a ultima posição do Servo na variavel global
            
          } else if(posi >= 180){ //Se o servo já tiver chegado ao final, ele volta o grau 0
            servo.write(0);
            posi = 0;
          }
          delay(500);
        }
        digitalWrite(led1, LOW);
      }else{
          digitalWrite(led1, HIGH); //Se houver muita luz internamente acenda um led
      }
      digitalWrite(led2, LOW);
  }else{
      digitalWrite(led2, HIGH); //Se houver sombra externamente acenda um led
  }
  delay(1000);
  
  Serial.println(sensor1);
  Serial.println(sensor2);

}
//Israel
