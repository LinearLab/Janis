/*
  Este programa liga o motor por 1 segundo, toda
  vez que recebe o caractere ASCCII "1" pela porta
  serial. A Velocidade da Porta Serial foi
  definida em 9600bps.
*/

int Value = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);
}

void loop()
{
  if (Serial.available() == 1) {
    Value = Serial.read();
    // Faremos o teste com o numero 49, que representa
    // "1" em ASCII
    if (Value == 49) {
      digitalWrite(2, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(2, LOW);
    }
  }
}