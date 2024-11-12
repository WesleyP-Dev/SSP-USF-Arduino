#define pinSensor 12
#define pinMotor  6
#define pinReset  2
#define pinBuzzer 7
#define pinledVerde 9
#define pinledAmarelo 10
#define pinledVermelho 11
#define pinRun 8

bool reset;

void setup() {
  // put your setup code here, to run once:

  // Inicia terminal SERIAL
  Serial.begin(9600);

  // Configura portas de entradas (INPUT) e saídas (OUTPUT)
  pinMode(pinReset,  INPUT);
  pinMode(pinSensor, INPUT);
  pinMode(pinRun, INPUT);
  pinMode(pinMotor,  OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinledVerde, OUTPUT);
  pinMode(pinledAmarelo, OUTPUT);
  pinMode(pinledVermelho, OUTPUT);
  reset = HIGH;
}

void loop() {

  //Estado Inicial
/////         = Se todos os sensores estiverem OK -> verde aceso
/////         = Buzzer desligado 
/////         = Motor desligado
/////         = Vermelho e verde apagados
  if(digitalRead(pinMotor) == LOW && digitalRead(pinSensor) == LOW && reset == HIGH && digitalRead(pinRun) == LOW){
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(pinledVerde, HIGH);
    digitalWrite(pinledAmarelo, LOW);
    digitalWrite(pinledVermelho, LOW);
    Serial.println("STATE 1"); // DEBUG
  }


/////      - Estado RUN (Motor ligado)
/////         = Pressionado botão de iniciar
/////         = Led amarelo aceso
/////         = Vermelho e verde apagados
  if((digitalRead(pinSensor) == LOW) && (digitalRead(pinRun) == HIGH) && (reset == HIGH)){
    digitalWrite(pinMotor, HIGH);
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(pinledVerde, LOW);
    digitalWrite(pinledAmarelo, HIGH);
    digitalWrite(pinledVermelho, LOW);  
    Serial.println("STATE 2"); // DEBUG
  }

/////      - Falha 
/////         = Vermelho aceso
/////         = Verde e amarelo apagados
/////         = Buzzer ligado
/////         = Aguardando ACKNOWLEDGE (Reconhecimento de alarme | Reset)
  if(digitalRead(pinSensor) == HIGH && digitalRead(pinMotor) == HIGH){
    digitalWrite(pinMotor, LOW);  
    digitalWrite(pinBuzzer, HIGH);
    digitalWrite(pinledVerde, LOW);
    digitalWrite(pinledAmarelo, LOW);
    digitalWrite(pinledVermelho, HIGH);
    reset = LOW;
    Serial.println("STATE 3"); // DEBUG
  }

/////      - Reset
/////         = Retorna ao estado inicial
  if(digitalRead(pinReset) == LOW && reset == LOW){
    reset = HIGH;
    Serial.println("STATE 4"); // DEBUG
  }
}

