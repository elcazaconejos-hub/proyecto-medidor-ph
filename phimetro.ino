const int pinPH = A0;
const int pinTo = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long sumaPH = 0;
  long sumaTo = 0;

  for (int i = 0; i < 20; i++) {
    sumaPH += analogRead(pinPH);
    sumaTo += analogRead(pinTo);
    delay(10);
  }

  float lecturaPH = sumaPH / 20.0;
  float lecturaTo = sumaTo / 20.0;

  float voltajePH = lecturaPH * (5.0 / 1023.0);
  float voltajeTo = lecturaTo * (5.0 / 1023.0);

  // Calibración provisional con tus datos anteriores
  float pH = 7.0 + (3.637 - voltajePH) * 10.067;

  // Conversión provisional, solo si tu salida To
  // corresponde a un sensor de 10 mV/°C desde 0 V
  float temperatura = voltajeTo * 100.0;

  Serial.print("pH: ");
  Serial.print(pH, 2);

  Serial.print(" | Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" °C");

  delay(1000);
}
