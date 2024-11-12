# Sistema de Segurança Pessoal (SSP) -  Arduino

Este projeto implementa o **Sistema de Segurança Pessoal (SSP)** utilizando um Arduino. O sistema monitora sensores e controla LEDs, motor e um buzzer para indicar diferentes estados operacionais. Ele é projetado para responder a eventos como falhas e reset, fornecendo uma interface de segurança eficaz.

## 🛠️ **Funcionamento do Sistema**

O SSP opera com quatro estados principais:

1. **Estado Inicial**:  
   - LED Verde aceso (sistema em repouso).  
   - Motor e buzzer desligados.

2. **Estado RUN** (Operação normal):  
   - Motor ligado.  
   - LED Amarelo aceso.  
   - LEDs Verde e Vermelho apagados.

3. **Estado de Falha**:  
   - LED Vermelho aceso.  
   - Motor desligado.  
   - Buzzer ativado para indicar a falha.

4. **Reset**:  
   - Retorna ao estado inicial após reconhecimento do alarme.

## ⚙️ **Hardware Utilizado**

- **Arduino** (modelo compatível com as bibliotecas básicas).  
- **Sensores**:  
  - Sensor de presença (conectado ao `pinSensor`).  
- **Atuadores**:  
  - Motor (controlado pelo `pinMotor`).  
  - Buzzer (conectado ao `pinBuzzer`).  
- **LEDs** para indicar os estados do sistema:  
  - Verde (`pinledVerde`) - Estado inicial.  
  - Amarelo (`pinledAmarelo`) - Estado RUN.  
  - Vermelho (`pinledVermelho`) - Estado de falha.  
- **Botões**:  
  - Botão de reset (`pinReset`).  
  - Botão de iniciar (`pinRun`).

## 🚀 **Como Utilizar**

1. Conecte os componentes ao Arduino conforme os pinos definidos no código.  
2. Carregue o código para o Arduino usando o Arduino IDE.  
3. Monitore o comportamento do sistema conforme os eventos (presença detectada, reset, etc.).  
4. Use o monitor serial para depuração e verificar os estados operacionais.




