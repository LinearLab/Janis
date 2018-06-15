/*
  Este programa liga o motor por 1 segundo, toda
  vez que recebe o caractere ASCCII "1" pela porta
  serial. A Velocidade da Porta Serial foi
  definida em 115200bps.
*/

int Value = 0;
int MOTOR = D4;

void setup()
{
  Serial.begin(115200);

  pinMode(MOTOR, OUTPUT);
}

void loop()
{
  if (Serial.available() == 1) {
    Value = Serial.read();
    // Faremos o teste com o numero "1" em ASCII
    if (Value == '1') {
      digitalWrite(MOTOR, HIGH);
      delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(MOTOR, LOW);
    }
  }
}
