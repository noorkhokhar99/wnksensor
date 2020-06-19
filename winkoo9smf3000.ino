#include <Wire.h>
unsigned char a,b,c;

float f;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Wire.begin();
  Wire.beginTransmission(0x40);
  Wire.write(0x10);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.begin();
  Wire.requestFrom(0x40,3);
  delay(500);
  a=Wire.read();
  b=Wire.read();
  c=Wire.read();
  Wire.endTransmission();

  f=((a*256+b)-32000)/140;
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(f);

  
}
