//Código - Robô Seguidor de Faixa:
//Iremos fazer as definições dos pinos de controle do motor, ou seja, suas saídas e entradas, envolvendo sensores e ponte H 

//Sensores
#define SD 8 //sensor para Direita
#define SE 9 //sensor para Esquerda
#define SF 10 //sensor para frente

//Ponte H
#define IN1 7 //saída 1
#define IN2 6 //saída 2
#define IN3 5 //saída 3
#define IN4 4 //saída 4 
#define ENA 11
#define ENB 12

//Inserindo variaveis
int SensorD = 0;
int SensorE = 0;
int SensorF = 0; // Variável responsável por controlar a velocidade dos motores.
int Controle = 255; // Variável de controle da velocidade
char ultimaDirecao = 'C';

void ConfigDosMotores () 

{
//Setando os pinos de controle dos motores como saída.
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode (ENA, OUTPUT);
pinMode (ENB, OUTPUT);
  
//Setando os pinos dos sensores como entrada.
pinMode (SD, INPUT);
pinMode (SE, INPUT);
pinMode (SF, INPUT);
  
//Desligando enables para a segurança do robô seguidor de faixa, evitando com que ele ligue sem querer os seus motores
digitalWrite(ENA,0);
digitalWrite(ENB,0);
Serial.begin(9600);
}

//Criando a leitura dos sensores
void LeituraSensores() {
  SensorD = digitalRead(SD);
  SensorE = digitalRead(SE);
  SensorF = digitalRead(SF);
  }

//Programação para o robô ir para frente
 void RoboParaFrente() 
{
  analogWrite(ENA, Controle*0.625); //Setando a velocidade dos motores
  analogWrite(ENB, Controle*0.625); //Setando a velocidade dos motores
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
}

//Programação para o robô ir para Esquerda
  void RoboParaEsquerda() 
{
  analogWrite(ENA, Controle*0.625);//Setando a velocidade dos motores
  analogWrite(ENB,Controle*0.625); //Setando a velocidade dos motores
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  }

//Programação para o robô ir para Direita
  void RoboParaDireita() 
{
    analogWrite(ENA, Controle*0.625); //Setando a velocidade dos motores
    analogWrite(ENB,Controle*0.625); //Setando a velocidade dos motores
    digitalWrite(IN1,0);
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN4,1);
  }

//Lógica para o robô seguir as curvas
    void ControleDoRobo() 
{
    if(SensorD == 1 && SensorE == 0 && SensorF == 1)  { RoboParaEsquerda(); } // 0 = Branca (Sem reflexão de luzes) 1 = Preto (Reflete luz para o sensor)
    if(SensorD == 0 && SensorE == 1 && SensorF == 1)  { RoboParaDireita(); }
    if(SensorD == 1 && SensorE == 1 && SensorF == 0)  { RoboParaFrente(); }
}

  
    
   
    void setup () 
{
    ConfigDosMotores();
}
    void loop() 
{
      LeituraSensores();
      ControleDoRobo();
}
