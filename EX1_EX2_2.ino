void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void verde()
{
  digitalWrite(10,HIGH);
  delay(10000);
  digitalWrite(10,LOW);
}

void amarelo()
{
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
}

void vermelho()
{
  digitalWrite(12,HIGH);
  delay(6000);
  digitalWrite(12,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  verde();
  amarelo();
  vermelho();

}
