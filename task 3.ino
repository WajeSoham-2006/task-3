#include <DHT.h>

const int DHTPIN = 2;
const int DHTTYPE = DHT22;

const int buzzerPin = 8;
const int threshold = 30;
const int RED_LED_PIN = 7;   
const int GREEN_LED_PIN= 9;   


DHT ht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  ht.begin();

  pinMode(buzzerPin, OUTPUT);
  pinMode(RED_LED_PIN,   OUTPUT);  
  pinMode(GREEN_LED_PIN, OUTPUT); 

}

void loop() {

  float humidity = ht.readHumidity();
  float temperature = ht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature > threshold) {
    tone(buzzerPin, 1000);
    digitalWrite(RED_LED_PIN,   HIGH);  
    digitalWrite(GREEN_LED_PIN, LOW);   
    Serial.println("WARNING! Temperature HIGH");
  }
  else {
    noTone(buzzerPin);
    digitalWrite(RED_LED_PIN,   LOW);   
    digitalWrite(GREEN_LED_PIN, HIGH);

    Serial.println("Temperature NORMAL");
  }

  Serial.println("----------------");

  delay(2000);
}




