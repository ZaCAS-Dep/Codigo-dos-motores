//Olá, iremos fazer um código com o uso da programação no Arduíno IDE para o robô segue faixa:
//Iremos fazer as definições dos pinos de controle do motor, ou seja, suas saídas e entradas, envolvendo sensores e ponte H 
#define SL 8 //Definindo os sensores para a leitura
#define SF 9 
#define SR 10 
#define IN1 7 //saída 1
#define IN2 6 //saída 2
#define IN3 5 //saída 3
#define IN4 4 //saída 4
#define ENA 3 //controla a velocidade do motor pela ponte H
#define ENB 13 //controla a velocidade do motor pela ponte H
int SensorL = 0;
int SensorF = 0;
int SensorR = 0; 
int Controle = 255; //Variável de controle da velocidade
char ultimaDirecao = 'C';

void ConfigDosMotores() 
{
//Setando os pinos de controle dos motores como saídas.
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode (ENA, OUTPUT);
pinMode (ENB, OUTPUT);
//Setando os pinos dos sensores como entradas.
pinMode (SL, INPUT);
pinMode (SF, INPUT);
pinMode (SR, INPUT);
//Desligando enables para a segurança do robô seguidor de faixa, evitando com que ele ligue sem querer os seus motores
digitalWrite(ENA,0);
digitalWrite(ENB,0);
Serial.begin(9600);
}

//Criando a leitura dos sensores
void LeituraDoSensor() 

{
SensorL = digitalRead(SL);
SensorF = digitalRead(SF);
SensorR = digitalRead(SR);
}

//Programação para o robô ir para frente
void RoboParaFrente() 

{
analogWrite(ENA, Controle*0.625);//usando 62,5% da velocidade 255 dos motores
analogWrite(ENB, Controle*0.625);
digitalWrite(IN1,0);
digitalWrite(IN2,1);
digitalWrite(IN3,0);
digitalWrite(IN4,1);
}

//Programação para o robô ir para Esquerda
void RoboParaEsquerda() 

{
  analogWrite(ENA, Controle*0.625);//usando 62,5% da velocidade 255 dos motores
  analogWrite(ENB,Controle*0.625);//usando 62,5% da velocidade 255 dos motores
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
}

//Programação para o robô ir para Direita
void RoboParaDireita() 
{
analogWrite(ENA, Controle*0.625);//usando 62,5% da velocidade 255 dos motores
analogWrite(ENB,Controle*0.625);//usando 62,5% da velocidade 255 dos motores
digitalWrite(IN1,0);
digitalWrite(IN2,0);
digitalWrite(IN3,0);
digitalWrite(IN4,1);
}

//Lógica para o robô seguir as curvas de forma correta
void ControleDoRobo() 
{
    if(SensorL == 1 && SensorF == 0 && SensorR == 1)  { RoboParaFrente(); }
    if(SensorL == 0 && SensorF == 1 && SensorR == 1)  { RoboParaEsquerda(); }
    if(SensorL == 1 && SensorF == 1 && SensorR == 0)  { RoboParaDireita(); }
}

  
    
//Colocando a lógica de início   
void setup () 
{
ConfigDosMotores();
}

//Colocando o sistema de vistória e aplicando a lógica de movimento
void loop()
{
LeituraDoSensor();
ControleDoRobo();
}

//Utilizando essa lógica e a montagem correta conseguimos concluir o percuso com o robô segue faixa.
