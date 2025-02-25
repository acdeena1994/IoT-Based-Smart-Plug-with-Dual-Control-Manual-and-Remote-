# IoT-Based-Smart-Plug-with-Dual-Control-Manual-and-Remote-
This project introduces an IoT-enabled smart plug that allows users to control electrical appliances through both manual switches and a smartphone app (Blynk). The system utilizes an ESP8266 microcontroller, a relay module, and a voltage sensor to provide real-time monitoring and seamless synchronization between manual and remote controls.
## 🔄 Working Methodology  
The smart plug system integrates both **manual** and **IoT-based control** to provide seamless operation:  

1. **Manual Control**:  
   - A **two-way switch** allows users to turn the plug ON/OFF manually.  
   - The relay detects the change and updates the plug’s state.  

2. **IoT Control via Blynk App**:  
   - The **ESP8266** receives ON/OFF commands from the Blynk app.  
   - It triggers the **relay module** to switch the plug accordingly.  
   - The system updates the **plug status** on the app in real time.  

3. **Real-Time Monitoring & Alerts**:  
   - A **voltage sensor** detects power flow.  
   - The ESP8266 transmits data to Blynk for **live tracking**.  

The **synchronized operation** ensures that whether controlled manually or remotely, the plug’s actual state is always reflected on the **Blynk dashboard**.  
