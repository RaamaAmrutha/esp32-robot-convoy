#include <esp_now.h>
#include <WiFi.h>

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  esp_now_init();

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  esp_now_add_peer(&peerInfo);

  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
  const char* msg = "MOVE_FORWARD";
  esp_now_send(broadcastAddress, (uint8_t *)msg, strlen(msg));
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  const char* msg2 = "STOP";
  esp_now_send(broadcastAddress, (uint8_t *)msg2, strlen(msg2));
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
