#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "Krnk Reddy";
const char* password = "krnkreddy";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Simulated sensor readings
int gasValue = 0;
int waterLevel = 0;
bool tiltDetected = false;
bool irDetected = false;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi. IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<!DOCTYPE html><html><head><title>Manhole Dashboard</title>";
    html += "<meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1'>";
    html += "<meta http-equiv='refresh' content='5'>";
    html += "<style>body { font-family: Arial; background: #f9f9f9; text-align: center; padding: 20px; }";
    html += ".card { background: #fff; padding: 20px; margin: 10px auto; border-radius: 12px; width: 300px; box-shadow: 0 0 10px #ccc; }</style></head><body>";
    html += "<h2>🚨 Manhole Monitoring Dashboard</h2>";

    html += "<div class='card'><h3>Gas Sensor</h3><p>" + String(gasValue) + " ppm</p></div>";
    html += "<div class='card'><h3>Water Level</h3><p>" + String(waterLevel) + " cm</p></div>";
    html += "<div class='card'><h3>Tilt Sensor</h3><p>" + String(tiltDetected ? "Tilt Detected" : "Stable") + "</p></div>";
    html += "<div class='card'><h3>IR Sensor</h3><p>" + String(irDetected ? "Obstacle Detected" : "Clear") + "</p></div>";

    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.begin();
}

void loop() {
  // Simulate random readings
  gasValue = random(50, 300);           // 50–300 ppm
  waterLevel = random(5, 35);           // 5–35 cm
  tiltDetected = random(0, 2);          // true or false
  irDetected = random(0, 2);            // true or false

  delay(5000); // Wait 5 seconds to match refresh rate
}
