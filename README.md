# **Signal X Firmware**

Welcome to **Signal X Firmware**, the **ultimate** custom firmware designed to **expand the capabilities** of your **Flipper Zero, M5StickC Plus, M5StickC Plus 2, Cardputer, LilyGO T-Embed CC1101, ESP8266 Deauther, ESP32, and more**! 

Built by a dedicated community of **hackers, developers, and security enthusiasts**, Signal X delivers a **powerful set of tools** for wireless testing, hardware hacking, and advanced emulation.

---

## **🚀 Features**
### **🔥 Sub-GHz (CC1101 Support)**
- **Signal Reading & Emulation** – Capture and replay remote signals.
- **Spectrum Analyzer** – Scan and visualize active RF frequencies.
- **Signal Jamming** – Disrupt weak Sub-GHz signals.
- **Signal Saving & Organization** – Store and manage Sub-GHz transmissions.
- **Full Compatibility** – Works with **Flipper Zero, LilyGO T-Embed CC1101, ESP32, and M5 devices**.

### **📶 Wi-Fi Attacks & Network Testing**
- **Wi-Fi Deauthentication** – Disconnect devices from networks.
- **Beacon Spam** – Create fake access points with customized SSIDs.
- **Evil Portal** – Set up phishing Wi-Fi login pages.
- **Packet Sniffing & Monitoring** – Analyze network activity.
- **ESP8266 & ESP32 Deauther** – Optimized for **ESP8266 Deauther firmware**.

### **🌀 Bluetooth (BLE) Exploits & Spam**
- **BLE Device Spoofing** – Emulate popular BLE devices.
- **BLE Spam (iOS, Android, Windows)** – Send disruptive BLE signals.
- **BLE Beacons & Advertising** – Broadcast custom BLE payloads.
- **BLE Packet Manipulation** – Modify and analyze BLE traffic.

### **📛 RFID & NFC Attacks**
- **RFID Cloning & Emulation** – Copy access cards & badges.
- **RFID Scanning & Saving** – Store multiple RFID tag profiles.
- **NFC Card Emulation** – Clone & replay NFC credentials.
- **Flipper Zero RFID Expansion** – Supports **high-frequency and low-frequency tags**.

### **📡 Infrared (IR) Remotes & Attacks**
- **IR Sending & Learning** – Capture & replay remote control signals.
- **Preloaded Database** – Access thousands of IR remotes.
- **TV-B-Gone Mode** – Turn off TVs in public places.
- **Custom IR Replay** – Play back stored IR signals.

---

## **📦 Installation Guide**
### **⚠️ Important: Backup Your Device Before Flashing!**

### **1️⃣ Download the Latest Release**
- Visit our **[GitHub Releases](https://github.com/lilbricky101/Signal-X-Firmware/releases)** page.
- Download the latest **Signal X Firmware** package for your device.

### **2️⃣ Flash the Firmware**
**Flipper Zero:**
- Use **qFlipper** to install Signal X firmware.
- Open **qFlipper**, navigate to **Firmware Update**, and select the downloaded **.dfu** file.
- Click **Flash** and wait for the process to complete.

**M5StickC, Cardputer, LilyGO T-Embed:**
- Install **M5Burner** or **ESPTool**.
- Flash the `.bin` file using the correct memory offsets.
- Restart your device.

**ESP8266 / ESP32:**
- Install **ESPFlasher** or use PlatformIO to build and upload.
- Run the flashing command in terminal:
  ```sh
  esptool.py --chip esp8266 --port COMX write_flash 0x00000 firmware.bin
  ```

---

## **🛠 Development & Contributions**
We encourage developers to contribute to **Signal X Firmware**! 

### **Get Started**
1️⃣ **Clone the Repository:**
```sh
git clone https://github.com/lilbricky101/Signal-X-Firmware.git
```
2️⃣ **Set Up Your Environment:**
- Follow the **Flipper Zero, M5Stack, or ESP32** firmware development guides.

3️⃣ **Make Changes & Submit a Pull Request**
- Implement new features, fix bugs, or improve documentation.
- Open a pull request on GitHub for review.

---

## **🤝 Community & Support**
Join our **Signal X Network** for the latest updates, discussions, and support!

🔹 **Discord:** [Join Signal X Network](https://discord.gg/r7QzDmsbyd)
🔹 **GitHub Issues:** Report bugs and request features.
🔹 **Wiki & Documentation:** Get detailed guides on usage and development.

---

## **📜 License**
**Signal X Firmware** is open-source under the **MIT License**. Feel free to use, modify, and distribute it!

---

## **🧑‍💻 Credits & Acknowledgments**
Signal X Firmware is developed by the **Signal X Community** – a passionate group of developers, hardware hackers, and researchers. 

Special thanks to **Flipper Zero Devs, M5Stack, ESP8266 Deauther Team, and Flipper-IRDB contributors** for their open-source tools that make this project possible.

---

⭐ **Support Us**
If you love **Signal X Firmware**, please consider **starring our GitHub repo** to support further development!

🚀 **[Star Signal X on GitHub](https://github.com/lilbricky101/Signal-X-Firmware)** 🚀

![2](https://github.com/user-attachments/assets/b4c4701f-a1a7-41e7-a64a-662ac217008f)
