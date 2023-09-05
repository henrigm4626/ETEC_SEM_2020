# Projeto Cofre com Senha - Teclado 4x4

![image](https://github.com/henrigm4626/ETEC_SEM_2020/assets/88845710/e2bb3312-87b5-4c7e-be71-898ad2fd8396)

## 🌐Link do Projeto
https://www.tinkercad.com/things/2nP72lGPUW0

## ℹMateriais
- 1 Arduino UNO
- 1 Protoboard
- 2 Resistores de 150Ω
- 1 LED Vermelho
- 1 LED Verde
- 1 Buzzer
- 1 Teclado 4x4
- 31 Jumpers

## ⚙️Funcionamento
Realizou-se este projeto usando como base o código para o teclado 4x4 oferecido pelos professores. Algumas alterações no código do teclado foram feitas, além da implementação do buzzer.

- Quanto ao funcionamento do projeto: o usuário terá 3 chances para digitar a senha correta, sendo que o programa realiza uma contagem de erros e informa no monitor serial quantas tentativas restam.
- Ao errar a senha 3 vezes consecutivas, o LED vermelho acenderá e o buzzer irá disparar como uma espécie de alarme. Já se o usuário acertar a senha definida, o LED verde acenderá.
- Para reiniciar o sistema, basta pressionar a tecla "*" que os LEDs e o Buzzer desligarão e a contagem de erros será redefinida.
