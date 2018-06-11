#include <PCU.h>
#include "DHT.h"

#define DEVICENAME "Geek IO"
#define DHTPIN 5
#define DHTTYPE DHT11

//PCU pcu(16,10,5,4,9);
PCU pcu(DHTPIN, 4, 13, 14, 9);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Setup sensor thresholds
float target_temp = 25;
float hist = 0.5;

// heartbeat to monitor if board dies
int hb = 0;

void setup() {
  // Start serial monitor
  delay(4000);
  Serial.begin(115200);
  delay(1000);
  Serial.print("Starting ");
  Serial.print(DEVICENAME);
  Serial.println("...");

  // Setup sensor threshold
  pcu.setTemperature(target_temp, hist);

  // Start DHT sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {
  // Wait one second every loop
  delay(1000);

  // Print keepalive message
  Serial.print("Keep alive "); Serial.println(hb); hb++;

  // Read sensors
  Serial.println(dht.readTemperature());
}

