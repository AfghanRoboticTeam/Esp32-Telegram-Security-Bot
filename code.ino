#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// WiFi credentials
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

// Telegram configuration
#define BOT_TOKEN "Your_Bot_Token"
#define CHAT_ID "Your_Chat_ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

// Sensor pins
#define PIR_SENSOR 14       // Motion sensor pin
#define SOUND_SENSOR 27     // Sound sensor pin
#define BUZZER 26           // Buzzer pin

// Alert status flags
bool motionDetected = false;
bool soundDetected = false;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  client.setInsecure();  // Bypass SSL verification

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected!");

  // Initialize sensors
  pinMode(PIR_SENSOR, INPUT);
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Send startup notification
  bot.sendMessage(CHAT_ID, "✅ System online and operational!", "");
}

void loop() {
  int motion = digitalRead(PIR_SENSOR);
  int sound = digitalRead(SOUND_SENSOR);

  // Motion detection logic
  if (motion == HIGH && !motionDetected) {
    Serial.println("🔴 Motion detected!");
    bot.sendMessage(CHAT_ID, "🚨 Alert: Suspicious movement detected!", "");
    tone(BUZZER, 1000, 500);  // Activate buzzer for 500 ms
    motionDetected = true;
  } 
  else if (motion == LOW) {
    motionDetected = false;
  }

  // Sound detection logic
  if (sound == HIGH && !soundDetected) {
    Serial.println("🔊 Abnormal sound detected!");
    bot.sendMessage(CHAT_ID, "⚠️ Warning: Unusual audio activity detected!", "");
    tone(BUZZER, 1500, 500);
    soundDetected = true;
  } 
  else if (sound == LOW) {
    soundDetected = false;
  }

  delay(2000); // Check every 2 seconds
}
