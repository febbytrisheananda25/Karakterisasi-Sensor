// Pin sensor
const int mq3Pin = A0;

// Konstanta sensor (dari datasheet MQ-3, sesuaikan untuk akurasi lebih tinggi)
const float A = 0.4;       // konstanta empiris
const float B = -0.35;     // konstanta empiris

// Parameter ADC dan resistor
const float RL = 10000.0;  // Resistor Load (RL) 10k ohm
const float Vc = 5.0;      // Tegangan catu (Vcc 5V Arduino)

// Nilai R0 dari hasil kalibrasi sebelumnya
float R0 = 27205.44;  // Gunakan nilai hasil kalibrasi

void setup() {
  Serial.begin(9600);
  Serial.print("Sensor MQ-3 aktif, R0 = ");
  Serial.print(R0);
  Serial.println(" ohm");
}

void loop() {
  int adcValue = analogRead(mq3Pin);
  float sensorVoltage = (adcValue / 1023.0) * Vc;
  float Rs = RL * (Vc - sensorVoltage) / sensorVoltage;
  float ratio = Rs / R0;

  float ppm = pow((ratio / A), (1.0 / B));

  Serial.print("Analog: ");
  Serial.print(adcValue);
  Serial.print("  | Tegangan: ");
  Serial.print(sensorVoltage);
  Serial.print(" V  | Rs: ");
  Serial.print(Rs);
  Serial.print(" Ω  | Ratio: ");
  Serial.print(ratio);
  Serial.print("  | ppm: ");
  Serial.println(ppm,6);

  delay(3000);
}
