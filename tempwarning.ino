

#include <DS18B20.h>

DS18B20 ds(2);
float POT = A2;
int KOUD = 4;
int WARM = 3;
int OK = 5;
void setup() {
  pinMode(KOUD, OUTPUT);
  pinMode(WARM, OUTPUT);
  pinMode(OK, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop() {
  // digitalWrite(WARM, 0);
  // digitalWrite(OK, 0);
  // digitalWrite(KOUD, 0);
  float TEMP = (ds.getTempC());
  float POTW = analogRead(POT);
  float selectie = 40 - (20 * (POTW / 1024));
  float VERSCHIL = (selectie - TEMP);

  if (VERSCHIL > 2) {
    digitalWrite(KOUD, 1);
  } else {
    digitalWrite(KOUD, 0);
  }
  if (VERSCHIL < -2) {
    digitalWrite(WARM, 1);
  } else {
    digitalWrite(WARM, 0);
  }
  if (VERSCHIL >= -2 && VERSCHIL <= 2) {
    digitalWrite(OK, 1);
  } else {
    digitalWrite(OK, 0);
  }
  Serial.println(TEMP);
  Serial.println(selectie);


  delay(500);
}