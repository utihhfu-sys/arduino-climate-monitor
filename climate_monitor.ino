// ============================================
//  Arduino Climate Monitor — DHT22 Sketch
//  Sends T:xx.x,H:xx.x over Serial @ 9600
// ============================================

#include <DHT.h>

#define DHTPIN   2       // Data pin connected to D2
#define DHTTYPE  DHT22   // DHT22 (AM2302) sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Climate Monitor v1.0");
  Serial.println("Initializing DHT22 sensor...");
  dht.begin();
  delay(2000); // Sensor warm-up
  Serial.println("Sensor ready.");
}

void loop() {
  float temperature = dht.readTemperature();  // Celsius
  float humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("ERROR: Failed to read from DHT22 sensor!");
  } else {
    // Output format: T:24.3,H:58.1
    Serial.print("T:");
    Serial.print(temperature, 1);
    Serial.print(",H:");
    Serial.println(humidity, 1);
  }

  delay(2000); // Wait 2 seconds between readings
}
