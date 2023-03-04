#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int Trigger = 3;
int Echo = 2;
long d, t;

void setup() {
  
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  lcd.init();//inciamos lcd
  lcd.backlight();// se activa la luz de fondo
  lcd.clear();

}

void loop() {
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t/59;
  Serial.print("Distancia:");
  Serial.print(d);
  Serial.println();
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("S1 ");
  lcd.print(d);
  lcd.display();
  delay(500);
  lcd.clear();
 
}
