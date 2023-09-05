#include <Wire.h>
#include <Keypad.h>
#define paswd_key 7 // Define 6 caracteres validos para o char mais 1 que pode ser NULL

char Data_db[paswd_key]; // 6 caracters mais 1 NULL = 7
char key_master[paswd_key] = "123456"; // Senha definida
byte matriz_db = 0, key_count = 0; // Declarando a matriz
char senha_acesso;
int erro = 2;
int contador = 0;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5}; // Pinos que correspondem às conexões
byte colPins[COLS] = {6,7,8,9}; // Pinos que correspondem às conexões

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int buzzerPin = 10;
const int led_red = 12;
const int led_green = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
}

void loop()
{
  senha_acesso = customKeypad.waitForKey();
  Serial.print(senha_acesso); //Imprime no monitor serial os botoes pressionados

    // Reiniciando o sistema
    if (senha_acesso == '*'){
        Serial.println(" "),
        Serial.print("Reset Acionado"),
        Serial.println(" "),
        digitalWrite(led_red, LOW),
        digitalWrite(led_green, LOW),
        noTone(buzzerPin);
        contador = 0,
        limpa_matriz(),
        Serial.flush ();
        return;
    }
    
  if (senha_acesso) {
    Data_db[matriz_db] = senha_acesso; // Armazena os dados pressionados do keypad na matriz
    matriz_db++; // Adiciona o dado pressionado pelo keypad na matriz e controla o numero de teclas pressionadas
  }
  
  if(matriz_db == paswd_key-1) { // "if" para comparar os dados retirados do keypad, trasnforamdos em matriz com o pasword

    if(!strcmp(Data_db, key_master)) // Compara matriz com a senha
    digitalWrite(led_green, HIGH), // Se for igual, acende o led verde
    Serial.println(" "),
    Serial.print("Chave digitada CORRETAMENTE");
    else
	contador ++, // Se não for igual, adiciona +1 no contador
    Serial.println(" "),
    Serial.print("Numero de erros: "),    
    Serial.print(contador),
    Serial.println(" de 3."), 
    limpa_matriz();
   	}
  
  if (contador > 2) { // Se o contador chegar a 3, acende o led vermelho
    digitalWrite(led_red, HIGH),
    tone(buzzerPin,450);
    Serial.flush (),
    Serial.println("Chave INCORRETA"),
    limpa_matriz(),
    Serial.println("Pressione *");
  }
  
}

void limpa_matriz()
{
  while(matriz_db !=0){
    Data_db[matriz_db--] = 0; // Limpa os dados digitados da matriz
  }
  return;
} 
