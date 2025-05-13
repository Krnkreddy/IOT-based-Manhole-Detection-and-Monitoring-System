# 🚨 Smart Manhole Monitoring System

This project is a prototype system designed to monitor manholes in urban areas using sensors for **gas detection**, **water level**, **tilt**, and **intrusion detection**. It provides two implementations:

- 🌐 **Wi-Fi Web Dashboard** using ESP32
- 📱 **GSM-Based SMS Alert System** using ESP32 + SIM800L

---
It looks like my browsing tool is temporarily down, so I can't access your GitHub repository directly. However, I can still give you suggestions based on what a well-structured GitHub repository for an IoT project like **"IOT-based Manhole Detection and Monitoring System"** should include.

Since you've uploaded **Arduino IDE code**, **website files**, and the **project report**, here's how you can organize and improve your repository:

---

2. **Project Description**

"An IoT-based system to detect hazardous manhole conditions using gas, water, tilt, and IR sensors. The system can alert users through SMS (GSM) or live dashboard (WiFi)."

3. **Features**

* Gas detection using MQ sensors
* Water level sensing with ultrasonic
* Tilt detection for open or misaligned covers
* IR-based presence detection
* Sends SMS alerts using SIM800L
* WiFi dashboard interface using ESPAsyncWebServer

4. **Hardware Used**

List your components:

* ESP32 Dev Module
* MQ-2 Gas Sensor
* HC-SR04 Ultrasonic Sensor
* Tilt Sensor
* IR Sensor
* SIM800L GSM Module
* SSD1306 OLED Display (optional)

5. **Circuit Diagram**

| **Component**       | **VCC**          | **GND** | **Signal Pin**             | **Notes**                 |
| ------------------- | ---------------- | ------- | -------------------------- | ------------------------- |
| GSM (SIM800L)       | XL6009 OUT+ (4V) | GND     | TX to GPIO16, RX to GPIO17 | Use voltage divider on RX |
| Ultrasonic Sensor   | 5V (Booster)     | GND     | Trig: GPIO18, Echo: GPIO19 | JSN-SR04T or HC-SR04      |
| IR Sensor           | 3.3V             | GND     | OUT: GPIO27                | Detects lid open/close    |
| GPS Module          | 3.3V or 5V       | GND     | TX: GPIO4, RX: GPIO2       | Soft serial               |
| Gas Sensor          | 5V               | GND     | A0 → GPIO34                | Analog                    |
| Tilt Sensor         | 3.3V             | GND     | OUT → GPIO26               | Digital HIGH/LOW          |
| Temp Sensor (DHT11) | 3.3V             | GND     | Data → GPIO25              | Or use LM35 to analog pin |
| Float Sensor        | 3.3V             | GND     | GPIO14                     | Digital HIGH/LOW          |
| Buzzer              | 3.3V             | GND     | GPIO15                     | Optional audible alert    |


6. **How to Use**

```bash
1. Clone the repo
2. Upload the desired .ino file using Arduino IDE
3. For dashboard version: Connect to WiFi and open IP in browser
4. For GSM version: Insert SIM and power module properly
```

7. **Screenshots**

![Screenshot 2025-05-04 112145](https://github.com/user-attachments/assets/544e41c2-ebfa-499c-a852-f80254768a1c)

8. **Online Source**

Modified some of the components and working according to out source and availability

https://iotdesignpro.com/projects/iot-manhole-monitoring-system
