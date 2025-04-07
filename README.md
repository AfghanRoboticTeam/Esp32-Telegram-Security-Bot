# 🚨 ESP32 Smart Security System with Telegram Alerts

[![Arduino CI](https://github.com/AfghanRoboticTeam/esp32-telegram-security-bot/actions/workflows/arduino-ci.yml/badge.svg)](https://github.com/AfghanRoboticTeam/esp32-telegram-security-bot/actions)
![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Platform](https://img.shields.io/badge/Platform-ESP32-00979D.svg)

A smart security system using ESP32 that detects motion/sound and sends real-time alerts to Telegram, with optional buzzer activation.

📺 **YouTube Tutorial:** [Watch Setup Guide](https://youtu.be/hbCDsZo1Kf8?si=xFP6TGxXmE560GR2)

## 🌟 Features
- Motion detection using PIR sensor
- Sound anomaly detection
- Instant Telegram notifications
- Visual (LED) and audible (buzzer) alerts
- Easy WiFi configuration
- Secure Telegram bot integration

## 📦 Hardware Requirements
- ESP32 Development Board
- PIR Motion Sensor (HC-SR501)
- Sound Detection Sensor
- Active Buzzer
- Jumper Wires
- Breadboard

## 🔧 Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/esp32-security-system.git

2. Install required libraries:
   - `WiFi.h`
   - `WiFiClientSecure.h`
   - `UniversalTelegramBot.h`

## ⚙️ Configuration
1. Update `ssid` and `password` in the code with your WiFi credentials
2. Create a Telegram bot using [@BotFather](https://t.me/BotFather) and update:
   - `BOT_TOKEN` with your bot token
   - `CHAT_ID` with your Telegram chat ID
3. Connect sensors:
   ```
   PIR Sensor  -> GPIO14
   Sound Sensor-> GPIO27
   Buzzer      -> GPIO26
   ```

## 🚀 Usage
1. Set up your Telegram bot following our [YouTube tutorial](https://youtu.be/hbCDsZo1Kf8?si=_fE2Jf_MdwqbHulE)
2. Upload the code to your ESP32
3. Test the system:
   - Wave hand in front of PIR sensor
   - Create loud noise for sound sensor
4. Receive Telegram alerts within 2 seconds!

## 📝 Notes
- Ensure stable WiFi connection
- Keep sensors away from direct airflow/noise sources
- For security, consider:
  - Using environment variables for credentials
  - Implementing proper SSL verification

## ❓ FAQ
**Q:** Not receiving Telegram messages?  
**A:** Verify your bot token and chat ID, ensure bot is started

**Q:** Sensors not triggering?  
**A:** Check wiring and sensor sensitivity adjustments

## 🤝 Contributing
Pull requests welcome! For major changes, please open an issue first.

## 📄 License
MIT © Afghan Robotic Team (https://github.com/AfghanRoboticTeam)
