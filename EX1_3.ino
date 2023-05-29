void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IntensidadeLuz = analogRead(A0);
  Serial.print("Intensidade da Luz: ");
  Serial.print(IntensidadeLuz);
  Serial.print("\n");
  if(IntensidadeLuz <= 550)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(5000);
}
