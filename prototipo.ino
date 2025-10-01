#include <WiFi.h>
#include <HTTPClient.h>

// === CONFIGURAÇÃO DO WIFI ===
const char* ssid     = "SEU_WIFI";
const char* password = "SENHA_WIFI";

// === PINO DO RELÉ ===
#define PINO_RELE  5   // Ajuste conforme a porta usada

void setup() {
  Serial.begin(115200);
  pinMode(PINO_RELE, OUTPUT);
  digitalWrite(PINO_RELE, LOW); // começa desligado

  // Conexão WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void loop() {
  // Exemplo: simulação de comando vindo de uma API (poderia ser Telegram ou App)
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando.equalsIgnoreCase("ligar")) {
      digitalWrite(PINO_RELE, HIGH);
      Serial.println("🔌 Tomada ligada!");
    }
    else if (comando.equalsIgnoreCase("desligar")) {
      digitalWrite(PINO_RELE, LOW);
      Serial.println("⚡ Tomada desligada!");
    }
    else {
      Serial.println("❓ Comando não reconhecido");
    }
  }

  delay(100);
}
