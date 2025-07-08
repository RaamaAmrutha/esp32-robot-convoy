#include <esp_now.h>
#include <WiFi.h>

#define LEFT_MOTOR_FORWARD  16
#define LEFT_MOTOR_BACKWARD 17
#define RIGHT_MOTOR_FORWARD 18
#define RIGHT_MOTOR_BACKWARD 19

void setupMotors() {
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void onDataReceive(const uint8_t *mac, const uint8_t *incomingData, int len) {
  char command[20];
  memcpy(command, incomingData, len);
  command[len] = '\0';

  Serial.print("Received command: ");
  Serial.println(command);

  if (strcmp(command, "MOVE_FORWARD") == 0) {
    moveForward();
  } else if (strcmp(command, "STOP") == 0) {
    stopMotors();
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  setupMotors();
  stopMotors();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onDataReceive);
}

void loop() {
}
