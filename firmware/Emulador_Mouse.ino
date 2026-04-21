//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                              BIBLIOTECA
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Mouse.h>

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                             VARIAVEIS
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int horzPin = A0;                                                                                 // porta analogica horizontal do pino do joystick 
int vertPin = A2;                                                                                 // porta analogia vertical do pino do joystick 
int selPin = 9;                                                                                   // botão do joystick

int vertZero, horzZero;                                                                           // Armazena o valor inicial de cada eixo, geralmento ao redor de 512
int vertValue, horzValue;                                                                         // Armazena o valor atual analógico output de cada eixo
const int sensitivity = 200;                                                                      // Maior valor de sensibilidade = mouse mais lento, ideal em torno de 500
int mouseClickFlag = 0;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                              SETUP
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  pinMode(horzPin, INPUT);                                                                        // define os dois pinos analógicos como inputs
  pinMode(vertPin, INPUT);
  pinMode(selPin, INPUT);                                                                         // define o pino do botão select como input 
  digitalWrite(selPin, HIGH);                                                                     // define o botão como high
  delay(1000);                                                                                    // pequeno delay para deixar os outputs se ajeitarem 
  vertZero = analogRead(vertPin);                                                                 // pega os valores iniciais
  horzZero = analogRead(horzPin);                                                                 // Joystick deve estar em uma posição neutra enquanto estiver rodando essa parte do código 

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            LOOP PRINCIPAL
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop()
{
  vertValue = analogRead(vertPin) - vertZero;                                                     // Lê a posição vertical e guarda os valores
  horzValue = analogRead(horzPin) - horzZero;                                                     // Lê a posição horizontal e guarda os valores
 

  Serial.print("x ");
  Serial.println(horzValue);
  Serial.print("y ");
  Serial.println(vertValue);
 
 

                                                                                                  

  if (vertValue != 0)   // verifica se o eixo x tem algum movimento
    Mouse.move(0, vertValue/sensitivity, 0); //quando ele verifica que existe movimento no eixo x entao ele usa a função move que envia os parametros (y,x,quantidades de movimentos no eixo) 
  if (horzValue != 0)  // verifica se o eixo y tem algum movimento
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
