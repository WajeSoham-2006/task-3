const int tempPin = A0;     // TMP36 analog output
const int fanLED  = 8;      // Fan / cooling indicator
const int buzzer  = 9;      // Alert buzzer
const float TEMP_THRESHOLD = 30.0;  // Threshold in °C

void setup() {
  Serial.begin(9600);
  pinMode(fanLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("=====================================");
  Serial.println(" Smart IoT Automation System - Task 3");
  Serial.println("       (TMP36 Sensor Version)");
  Serial.println("=====================================");
  delay(2000);
}

void loop() {
  int rawValue = analogRead(tempPin);          // 0-1023
  float voltage = rawValue * (5.0 / 1024.0);   // Convert to volts
  float temperature = (voltage - 0.5) * 100.0; // TMP36: 10mV/°C, 0.5V offset at 0°C

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(fanLED, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Status: Temperature HIGH -> Fan/Alert ON");
  } else {
    digitalWrite(fanLED, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Status: Temperature Normal -> Fan/Alert OFF");
  }

  Serial.println("-------------------------------------");
  delay(2000);
}