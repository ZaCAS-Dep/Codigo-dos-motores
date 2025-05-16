//Código de programação - Robô Seguidor de Linha:
//Definições dos pinos de controle do motor.
#define SL 8 //sensor para esquerda
#define SF 9 //sensor para direita
#define SR 10 //sensor para frente
#define IN1 7 //saída 1
#define IN2 6 //saída 2
#define IN3 5 //saída 3
#define IN4 4 //saída 4- saídas ponte H
#define ENA 11
#define ENB 12
int SensorL = 0;
int SensorF = 0;
int SensorR = 0; //variável responsável por controlar a velocidade dos motores.
int Controle = 255; //Controle da velocidade
char ultimaDirecao = 'C';

void ConfigMotores () {
//Setamos os pinos de controle dos motores como saída.
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode (ENA, OUTPUT);
pinMode (ENB, OUTPUT);
//Setando os pinos dos sensores como entrada.
pinMode (SL, INPUT);
pinMode (SF, INPUT);
pinMode (SR, INPUT);
//Desligando enables por segurança
digitalWrite(ENA,0);
digitalWrite(ENB,0);
Serial.begin(9600);
}

void LeituraSensor() {
  SensorL = digitalRead(SL);
  SensorF = digitalRead(SF);
  SensorR = digitalRead(SR);
  }
 
 void RoboFrente() {
  analogWrite(ENA, Controle*0.625);
  analogWrite(ENB, Controle*0.625);
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  }
  void RoboEsquerda() {
  analogWrite(ENA, Controle*0.625);
  analogWrite(ENB,Controle*0.625);
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  }
  void RoboDireita() {
    analogWrite(ENA, Controle*0.625);
    analogWrite(ENB,Controle*0.625);
    digitalWrite(IN1,0);
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN4,1);
    }

    void ControleRobo() {
   
    if(SensorL == 1 && SensorF == 0 && SensorR == 1)  { RoboFrente(); }
    if(SensorL == 0 && SensorF == 1 && SensorR == 1)  { RoboEsquerda(); }
    if(SensorL == 1 && SensorF == 1 && SensorR == 0)  { RoboDireita(); }
    }

  
    
   
    void setup () {
    ConfigMotores();
    }
    void loop() {

      
      LeituraSensor();
      ControleRobo();
      }
