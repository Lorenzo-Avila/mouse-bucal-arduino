#include <Mouse.h>

// --- CONFIGURAÇÕES E PINOS ---
const int horzPin = A0; // porta analogica horizontal do pino do joystick 
const int vertPin = A2; // porta analogia vertical do pino do joystick 
const int selPin = 9;  

// --- PARÂMETROS DE CONTROLE ---                                                                        
const int DEADZONE = 15; // zona morta, ou seja, o valor mínimo que o joystick precisa para ser considerado um movimento, ideal em torno de 15
const int sensitivity = 200;                                                                      // Menor valor = mais rápido


int vertZero, horzZero; // Armazena o valor inicial de cada eixo
int vertValue, horzValue; // Armazena o valor atual analógico output de cada eixo
int mouseClickFlag = 0;



// --- SETUP ---
void setup(){
  Serial.begin(9600);
  pinMode(horzPin, INPUT);                                                                        // define os dois pinos analógicos como inputs
  pinMode(vertPin, INPUT);
  pinMode(selPin, INPUT_PULLUP);                                                                   // define o pino do botão select como input com pullup interno, ou seja, ele vai ler 1 quando o botão não for pressionado e 0 quando for pressionado
  delay(1000);                                                                                    // pequeno delay para deixar os outputs se ajeitarem 
  vertZero = analogRead(vertPin);                                                                 // pega os valores iniciais
  horzZero = analogRead(horzPin);                                                                 // Joystick deve estar em uma posição neutra enquanto estiver rodando essa parte do código 
}


// --- LOOP ---
void loop()
{
  vertValue = analogRead(vertPin) - vertZero;                                                     // Lê a posição vertical e guarda os valores
  horzValue = analogRead(horzPin) - horzZero;                                                     // Lê a posição horizontal e guarda os valores
 

  Serial.print("x ");
  Serial.println(horzValue);
  Serial.print("y ");
  Serial.println(vertValue);

  if (abs(vertValue) > DEADZONE)  // verifica se o eixo x tem algum movimento
    Mouse.move(0, vertValue/sensitivity, 0); //quando ele verifica que existe movimento no eixo x entao ele usa a função move que envia os parametros (y,x,quantidades de movimentos no eixo) 
  if (abs(horzValue) > DEADZONE)  // verifica se o eixo y tem algum movimento
    Mouse.move((horzValue/sensitivity) ,0, 0); //quando ele verifica que existe movimento no eixo y entao ele usa a função move que envia os parametros (y,x,quantidades de movimentos no eixo)                                                // move o mouse no eixo x 

    
  if ((digitalRead(selPin) == 0) && (!mouseClickFlag))                                            // se o botão do joystick é pressioando
  {
    mouseClickFlag = 1;
    Mouse.press(MOUSE_LEFT);                                                                      // clica o botão esquerdo
  }
  else if ((digitalRead(selPin))&&(mouseClickFlag))                                               // Se o botão do joystick não é pressioando 
  {
    mouseClickFlag = 0;
    Mouse.release(MOUSE_LEFT);                                                                    // deixa o botão esquerdo livre
  }
}
