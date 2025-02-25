#define BLYNK_TEMPLATE_ID "***********"
#define BLYNK_TEMPLATE_NAME "*********"
#define BLYNK_AUTH_TOKEN "************"

// Include libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

// Your WiFi credentials
char ssid[] = "********"; // Enter your WiFi Name
char pass[] = "********"; // Enter your WiFi Password

// Blynk Authentication Token from the Blynk app
char auth[] = "********************";

// Pin Definitions
const int relayPin = D1;         // Relay connected to GPIO 5 (D1 on NodeMCU)
const int voltageSensorPin = A0; // Connect the voltage sensor to A0 pin
float voltageThreshold = 12.00;  // Threshold voltage in volts

BlynkTimer timer;

// Voltage divider resistor values (adjust based on your actual circuit)
const float R1 = 30000.0; // Resistor 1 (10k ohms)
const float R2 = 7500.0;  // Resistor 2 (1k ohms)

// Function to read voltage sensor
float readVoltage() {
  int sensorValue = analogRead(voltageSensorPin);
  float voltage = (sensorValue * 3.3) /1024.0; // Convert to actual ADC voltage
  voltage = voltage * (R1 + R2) / R2;           // Adjust based on voltage divider ratio
  return voltage;
}

// Function to check voltage and update LED on Blynk
void checkVoltage() {
  float voltage = readVoltage();
  Serial.print("Voltage: ");
  Serial.println(voltage);

  if (voltage == 0) {
    Blynk.virtualWrite(V3, 255); // Turn on virtual LED on V3
    Serial.println("Voltage exceeds 12V, LED ON");
  } else {
    Blynk.virtualWrite(V3, 0);   // Turn off virtual LED on V3
    Serial.println("Voltage below 12V, LED OFF");
  }
}

// Function to toggle relay state
void toggleRelay() {
  static bool relayState = false; // Current state of relay
  relayState = !relayState;
  digitalWrite(relayPin, relayState ? HIGH : LOW);
  Blynk.virtualWrite(V1, relayState);      // Sync Blynk app
  Serial.print("Relay is now ");
  Serial.println(relayState ? "ON" : "OFF");
}

// Blynk control for relay
BLYNK_WRITE(V1) {
  bool blynkCommand = param.asInt();
  digitalWrite(relayPin, blynkCommand ? HIGH : LOW); // Update relay state
  Serial.print("Relay turned ");
  Serial.println(blynkCommand ? "ON via Blynk" : "OFF via Blynk");
}

// Setup
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);             // Start with relay off

  timer.setInterval(1000L, checkVoltage);  // Check voltage every second
}

// Main loop
void loop() {
  Blynk.run();
  timer.run();
}
