## 🛠 Components & Connections

### 1. ESP8266 (Microcontroller)
- Acts as the **brain** of the system, processing inputs from the **Blynk cloud** and the **two-way switch**.
- Controls the **relay module** to turn the appliance **ON/OFF**.
- Continuously monitors the **voltage sensor** for power status.

### 2. Relay Module
- Functions as an **electronic switch** to control the AC power going to the **plug and appliance**.
- Connected to the **ESP8266 GPIO pins**, allowing control from both **Blynk and the two-way switch**.
- Ensures **synchronized operation** (i.e., when switched ON via manual switch, **Blynk reflects the change**).

### 3. Two-Way Switch
- **Manually controls** the relay and appliance.
- **Works interchangeably** with Blynk, ensuring that either method can turn the device ON/OFF.
- Helps maintain control even when the **internet is unavailable**.

### 4. Plug with Switch
- Provides power to the **appliance (bulb, fan, etc.)**.
- Allows for easy **AC power connection**.

### 5. Voltage Sensor
- **Monitors** real-time voltage consumption.
- Sends voltage readings to **ESP8266**, which updates the **Blynk app**.
- Helps in detecting **overload or fault conditions**.

### 6. Bulb (Load/Appliance)
- Represents the **device being controlled** (e.g., bulb, fan, or any electrical appliance).
- Powered through the **relay and two-way switch connection**.

### 7. Blynk Cloud (IoT Platform)
- Provides **remote control and monitoring** via the **Blynk mobile app**.
- Reflects real-time **switch states and voltage readings**.
- Users can toggle the appliance **ON/OFF** and receive **power usage updates**.

### 8. DC Power Source
- Provides **DC power** to the **ESP8266** and other circuit components.
- Ensures smooth operation of the **IoT system**.


## ⚡ Working Principle

### **1. Manual Mode (Two-Way Switch)**
- If the user **flips the two-way switch**, it **toggles the relay state**, turning the **appliance ON/OFF**.
- The ESP8266 **detects the switch change** and updates the **Blynk app accordingly**.

### **2. IoT Mode (Blynk App Control)**
- Users can **remotely control** the appliance via the **Blynk app**.
- The ESP8266 receives the command from Blynk and **activates/deactivates the relay**, toggling the **appliance**.
- The two-way switch remains **synchronized**, meaning its next physical flip will **change the relay state**.

### **3. Voltage Monitoring**
- The **voltage sensor** continuously measures the **power going to the appliance**.

### **4. Synchronization Between Manual & IoT Controls**
- The **ESP8266 ensures that the state of the switch and relay remain updated**, whether controlled manually or via **IoT**.
- If the **switch is toggled manually**, the **app will reflect the change**, and vice versa.
