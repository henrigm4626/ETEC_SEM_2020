# Projeto Dado Eletrônico com Sensor Ultrassônico e Servomotor

![image](https://github.com/henrigm4626/ETEC_SEM_2020/assets/88845710/cd91443a-ec63-42cb-91a3-aa4806ddcabc)


## 🌐Link do Projeto
https://www.tinkercad.com/things/6KeGEHZyAzH

## ℹMateriais
- 1 Arduino UNO
- 1 Protoboard
- 2 Mini Protoboards
- 7 Resistores de 100Ω
- 7 LEDs Vermelhos
- 1 Sensor de distância ultrassônico
- 1 Micro Servomotor
- 1 Buzzer
- 36 Jumpers

## ⚙️Funcionamento
Quando a distância de um objeto for menor de 30cm no sensor ultrassônico, será sorteado um valor de 1 a 6 no dado eletrônico, 
onde o valor 1 seria apenas um LED aceso, o valor 6 seriam seis acesos e assim em diante. 

Caso seja sorteado um número ímpar, o servomotor permanecerá parado e o “buzzer” emitirá um som. Já se for um número par, o servomotor irá rotacionar 90° e o “buzzer” não emitirá nenhum som. 

Se o usuário quiser sortear novamente, basta apenas esperar alguns segundos ou impor uma distância maior de 30cm no sensor ultrassônico (onde não ocorreria nenhum sorteio) e em seguida uma menor.
