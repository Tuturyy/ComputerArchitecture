#include <LiquidCrystal.h>

int t = 0, soma = 0, max = 0, min = 1023, y = 0;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IntensidadeLuz = analogRead(A0);
  delay(500);
  soma += IntensidadeLuz;
  //Serial.print("Intensidade da Luz: ");
  //Serial.print(IntensidadeLuz);
  Serial.print("\n");
  lcd.setCursor(0, 0);
  lcd.print("min");
  lcd.setCursor(4, 0);
  lcd.print("max");
  lcd.setCursor(8, 0);
  lcd.print("med");
  lcd.setCursor(12, 0);
  lcd.print("int");
  lcd.setCursor(12, 1);
  lcd.print(IntensidadeLuz);
  if(IntensidadeLuz > max)
  {
    max = IntensidadeLuz;
  }
  if(IntensidadeLuz < min)
  {
    min = IntensidadeLuz;
  }
  if((t < 20) && (t%2 == 0))
  {
    lcd.setCursor(y,1);
  	lcd.write('.');
    y++;
    if(y == 10)
    {
      lcd.clear();
      y = 0;
    }
  }
  if(t == 19)
  {
    int media = soma/20;
    lcd.setCursor(0, 1);
    lcd.print(min);
    lcd.setCursor(4, 1);
    lcd.print(max);
    lcd.setCursor(8, 1);
    lcd.print(media);
    delay(5000);
    lcd.clear();
    t = -1, soma = 0, min = 1023, max = 0;
  }
  t++;
}
