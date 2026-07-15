#include "arduino_secrets.h"
#include <DHT.h>

#define DHTPIN 23     
#define DHTTYPE DHT11 
#define RELAY_PIN 19
#define INTERVAL 2000

DHT dht(DHTPIN, DHTTYPE);

#include "thingProperties.h"
unsigned long lastReadTime = 0; 

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  unsigned long currentMillis = millis();
  if (currentMillis - lastReadTime >= INTERVAL) {
    lastReadTime = currentMillis;

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h)) {
      temp = t;
      humidity = h;
      
      Serial.print("Temp: ");
      Serial.print(temp);
      Serial.print(" *C | Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");
    } else {
      Serial.println("Failed read DHT11 sensor!");
    }
  }
}


/*
  Since Relay is READ_WRITE variable, onRelayChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onRelayChange()  {
  Serial.print("Relay State: ");
  Serial.println(relay ? "ON" : "OFF");
  digitalWrite(RELAY_PIN, relay);
}
