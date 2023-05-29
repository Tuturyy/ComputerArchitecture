volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),blink, CHANGE);
  Serial.begin(9600);
}

void blink()
{
  state = !state;
}

void amareloCarroVermelhoPeao()
{
  int x = 0;

  while(x < 1000)
  {
    digitalWrite(11,HIGH);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    delay(100);
    x = x + 100;
  }
  while(x < 3000)
  {
    digitalWrite(11,HIGH);
    digitalWrite(8,HIGH);
    delay(100);
    x = x + 100;
    digitalWrite(11,LOW);
    digitalWrite(8,LOW);
    delay(100);
    x = x + 100;
  }
}
void vermelhoCarroVerdePeao()
{
  int x = 0;
  int r = 6;

  while(x < 4000)
  {
    relogio(r);
    r--;
    digitalWrite(12,HIGH);
    digitalWrite(9,HIGH);
    delay(100);
  x = x + 100;
  }
  while(x < 6000)
  {
    relogio(r);
    r--;
    digitalWrite(12,HIGH);
    digitalWrite(9,HIGH);
    delay(100);
    x = x + 100;
    digitalWrite(12,LOW);
    digitalWrite(9,LOW);
    delay(100);
    x = x + 100;
  }
}

void um()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(13, LOW);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(13, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(7, LOW);
}

void dois()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(7, HIGH);
  delay(1000);
}

void tres()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
}

void quatro()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(13, LOW);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
}

void cinco()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
}

void seis()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
}

void relogio(int x)
{
  if(x == 1)
  {
    um();
  }
  if(x == 2)
  {
    dois();
  }
  if(x == 3)
  {
    tres();
  }
  if(x == 4)
  {
    quatro();
  }
  if(x == 5)
  {
    cinco();
  }
  if(x == 6)
  {
    seis();
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int t = 0;
  state = LOW;
  while((t < 10000) && (state == LOW))
  {
    Serial.print(state);
    while((t < 8000) && (state == LOW))
    {
      digitalWrite(10,HIGH);
      digitalWrite(8,HIGH);
      delay(100);
      t = t + 100;
    }
    while((t < 10000) && (state == LOW))
    {
      digitalWrite(10,HIGH);
      digitalWrite(8,HIGH);
      delay(100);
      t = t + 100;
      digitalWrite(10,LOW);
      digitalWrite(8,LOW);
      delay(100);
      t = t + 100;
    }
  }
  digitalWrite(10,LOW);
  digitalWrite(8,LOW);
  delay(100);
  amareloCarroVermelhoPeao();
  vermelhoCarroVerdePeao();

}
