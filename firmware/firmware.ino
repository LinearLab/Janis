/*
  Este programa liga o motor por 1 segundo, toda
  vez que recebe o caractere ASCCII "1" pela porta
  serial. A Velocidade da Porta Serial foi
  definida em 9600bps.
*/
char Value = 0;
int MOTOR = D8;
int LED = D4;
long int count;
#define TEMPO_OFF 116279  //~1 segundo
#define TEMPO_ON  100 //840us
void setup()
{
  Serial.begin(9600);

  Serial.println("Sistema Ligado");
  pinMode(MOTOR, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(MOTOR, LOW);
  digitalWrite(LED, HIGH);
}

void loop()
{
  if (Serial.available()) 
  {
    
    Value = Serial.read();
    // Faremos o teste com o numero "1" em ASCII
    if (Value == '1') 
    {
      digitalWrite(MOTOR, HIGH);
      digitalWrite(LED, LOW);
      Serial.println("Disparo Executado");
      delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(LED, HIGH);
      digitalWrite(MOTOR, LOW);
      Value = 0;
      
    }
  }
  count++;
  if(count == TEMPO_OFF) digitalWrite(LED, LOW);
  else if(count == TEMPO_ON+TEMPO_OFF) 
  {
    digitalWrite(LED, HIGH);
    count = 0;
  }
  
  //delay(100);
}
