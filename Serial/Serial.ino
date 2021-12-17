#include <SoftwareSerial.h>

SoftwareSerial D1(2,3);

void setup() {
  D1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (D1.available())
  Serial.write(D1.read());

  if (Serial.available())
  D1.write(Serial.read());

}
