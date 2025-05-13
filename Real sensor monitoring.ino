#define sensor 21        // IR sensor GPIO
#define ECHOPIN 19       // Echo pin GPIO
#define TRIGPIN 18       // Trigger pin GPIO
#define SIM800L_TX 17    // SIM800L Tx GPIO
#define SIM800L_RX 16    // SIM800L Rx GPIO
int sensorPin = A0;     // Gas sensor (analog input)

// Create a HardwareSerial instance for SIM800L
HardwareSerial mySerial(1);  // Use Serial1 (pins 16 and 17)

void setup()
{
  Serial.begin(115200);       // Start serial monitor
  mySerial.begin(115200, SERIAL_8N1, SIM800L_RX, SIM800L_TX); // Initialize GSM serial
  pinMode(sensor, INPUT);          // IR sensor
  pinMode(ECHOPIN, INPUT_PULLUP);  // Echo pin (Ultrasonic sensor)
  pinMode(TRIGPIN, OUTPUT);        // Trigger pin (Ultrasonic sensor)

  delay(1000);  // Allow SIM800L to initialize
}

void loop()
{
  int readings = digitalRead(sensor); // Read IR sensor value
  int val = analogRead(A0);           // Read gas sensor value

  // Measure distance using ultrasonic sensor
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIGPIN, LOW);
  int distance1 = pulseIn(ECHOPIN, HIGH, 26000);
  int distance = distance1 / 58;
  Serial.println(distance);
  Serial.println(" cm");
  delay(500);

  // Tilt detection (IR sensor)
  if (readings == 1) 
  { 
    sendSMS("Tilt Detected");
  }

  // Water level detection (ultrasonic sensor)
  if (distance <= 20) 
  { 
    sendSMS("Water Level Reached");
  }

  // Gas detection (MQ sensor)
  if (val > 80) 
  { 
    sendSMS("Gas Detected");
  }

  delay(1000); // Delay for 1 second before the next loop
}

// Function to send SMS using SIM800L
void sendSMS(String message)
{
  mySerial.println("AT"); 
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Set SMS format to text
  updateSerial();
  mySerial.println("AT+CMGS=\"+919829559608\""); // Replace with your phone number
  updateSerial();
  mySerial.print(message); // Message content
  updateSerial();
  mySerial.write(26);  // Send SMS
}

// Function to forward serial data between Serial and mySerial
void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());  // Forward what Serial received to HardwareSerial
  }
  while (mySerial.available()) 
  {
    Serial.write(mySerial.read());  // Forward what HardwareSerial received to Serial
  }
}
