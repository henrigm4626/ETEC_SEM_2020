# Projeto Semáforo com Timer e Botão para Travessia de Pedestres

![image](https://github.com/henrigm4626/ETEC_SEM_2020/assets/88845710/52ebe47f-5026-4e86-8e9f-2e81464284d5)

## 🌐Link do Projeto
https://www.tinkercad.com/things/iLZ2M12nHWU

## ℹMateriais
- 1 Arduino UNO
- 1 Protoboard
- 13 Resistores de 150Ω
- 1 Resistor de 10kΩ
- 5 LEDs Azuis
- 3 LEDs Vermelhos
- 2 LEDs Amarelos
- 3 LEDs Verdes
- 1 Botão
- 18 Jumpers

## ⚙️Funcionamento
- Inicialmente há 2 semáforos que permanecem abertos (luz verde acesa) por um tempo ilimitado. Caso alguém pressione o botão, o ciclo infinito da luz verde será quebrado 
e o timer contará 15 segundos para que os semáforos ficarem amarelos. 

- Com os semáforos amarelos, o timer contará aproximadamente 6 segundos para tornarem-se vermelhos.

- No momento que os semáforos fecharem (luz vermelha acesa), a luz verde de pedestre acenderá. Então, os pedestres terão 15 segundos até que os semáforos fiquem verdes e a luz de 
pedestre fique vermelha, reiniciando o ciclo.
