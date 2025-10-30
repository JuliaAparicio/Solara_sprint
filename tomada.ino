#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
 
// ======== WIFI ========
#define WIFI_SSID      "rede_fessor"
#define WIFI_PASSWORD  "F14p@2025@"
 
// ======== FIREBASE ========
#define API_KEY        "AIzaSyC1SlFO01GVZtSDa-XYWiuV0l4cGw9r-T0"
#define DATABASE_URL   "https://goodweapp-default-rtdb.firebaseio.com"
 
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool loginOK = false;
 
// ======== DISPLAY SSD1306 ========
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
 
// ======== SENSOR ========
const int PIN_SENSOR = 34;
const float VCC = 3.3;
const int ADC_MAX = 4095;
const float V_REDE = 127.0;
float VOLTS_PER_AMP = 0.100;
 
unsigned long sendDataPrevMillis = 0;
 
float adcToVolts(int raw) {
  return (raw * VCC) / (float)ADC_MAX;
}
 
void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}
 
void setupFirebase() {
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;
 
  // Login anônimo
  auth.user.signup = true;
 
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
 
  // Espera o token ficar pronto
  unsigned long t0 = millis();
  while (auth.token.uid == "" && millis() - t0 < 10000) {
    delay(200);
  }
 
  if (auth.token.uid != "") {
    loginOK = true;
    Serial.print("Login OK. UID: ");
    Serial.println(auth.token.uid.c_str());
  } else {
    Serial.println("Falha no login anônimo.");
  }
}
 
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar o display SSD1306"));
    for (;;);
  }
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Iniciando...");
  display.display();
 
  connectWiFi();
  setupFirebase();
 
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("WiFi + Firebase OK");
  display.display();
  delay(800);
}
 
void loop() {
  float soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += analogRead(PIN_SENSOR);
    delay(10);
  }
  float media = soma / 10.0;
  float volts = adcToVolts(media);
  float corrente = volts / VOLTS_PER_AMP;
  float potencia = corrente * V_REDE;
 
  Serial.print("Corrente: ");
  Serial.print(corrente, 2);
  Serial.print(" A | Potência: ");
  Serial.print(potencia, 1);
  Serial.println(" W");
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Corrente: ");
  display.print(corrente, 2);
  display.println(" A");
 
  display.setCursor(0, 25);
  display.print("Potencia: ");
  display.print(potencia, 1);
  display.println(" W");
 
  display.setCursor(0, 40);
  display.println(WiFi.status() == WL_CONNECTED ? "WiFi: OK" : "WiFi: Falhou");
  display.setCursor(0, 55);
  display.println(Firebase.ready() ? "Firebase: OK" : "Firebase: Falhou");
  display.display();
 
  if (Firebase.ready() && loginOK && (millis() - sendDataPrevMillis > 2000)) {
    sendDataPrevMillis = millis();
 
    String basePath = "/users/" + String(auth.token.uid.c_str()) + "/testes/esp32";
 
    if (Firebase.RTDB.setFloat(&fbdo, basePath + "/corrente", corrente)) {
      Serial.println("Corrente enviada");
    } else {
      Serial.print("Falha corrente: ");
      Serial.println(fbdo.errorReason());
    }
 
    if (Firebase.RTDB.setFloat(&fbdo, basePath + "/potencia", potencia)) {
      Serial.println("Potencia enviada");
    } else {
      Serial.print("Falha potencia: ");
      Serial.println(fbdo.errorReason());
    }
  }
}
