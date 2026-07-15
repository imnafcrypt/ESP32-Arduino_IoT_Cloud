# ESP32-Arduino_IoT_Cloud

This project connects an ESP32/Arduino board to the *Arduino IoT Cloud* to monitor temperature and humidity using a DHT11 sensor. It also allows remote control of a relay directly from the Arduino IoT Cloud dashboard.

## 🛠 Hardware Requirements

- **ESP32** Development Board
- **DHT11** Temperature and Humidity Sensor
- **5V Relay Module**

## 📦 Software Dependencies

- [Arduino_ConnectionHandler](https://github.com/arduino-libraries/Arduino_ConnectionHandler)
- [ArduinoIoTCloud](https://github.com/arduino-libraries/ArduinoIoTCloud)
- [DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library)

## 🚀 Setup & Configuration

**1. Clone or Download the Repository**

Ensure the `.ino` file is in the same directory as your credentials `arduino_secrets.h` & `thingProperties.h`.

**2. Configure Device Key & Wi-Fi**

Ensure your `arduino_secrets.h` file is set up correctly with your credentials.

```cpp
#define SECRET_DEVICE_KEY "<Your Client Secret>"
#define SECRET_OPTIONAL_PASS "<Your Network Password>"
#define SECRET_SSID "<Your Network SSID>"
```

**3. Configure CLIENT_ID**

Verify that `thingProperties.h` matches your cloud variables and Client ID.

```cpp
const char DEVICE_LOGIN_NAME[]  = "<Your Client ID>";

```
