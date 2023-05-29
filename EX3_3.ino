const int trigPin=4,echoPin=5;
int verde=13,amarelo=12,vermelho=11;
float duracao,distancia;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(9,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(amarelo,OUTPUT);
  pinMode(vermelho,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = (duracao*.0343)/2;
  int value = distancia;
   value = map(value,1,20,0,1000);
  Serial.print("value: ");
  Serial.println(value);
  Serial.println(distancia);
  delay(100);
  if(distancia<3)
  {
    digitalWrite(vermelho,HIGH);
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, HIGH);
    tone(9,800,1000);
  }
  if(distancia<8 && distancia>=3)
  {
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho,LOW);
    tone(9,800,value);
    delay(value);
  }
  if(distancia < 20 && distancia>=8)
  {
    digitalWrite(verde,HIGH);
    digitalWrite(amarelo, LOW);
   tone(9,800,value);
   delay(value);
  }
  if(distancia>20) {
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);
  }

}
