#include <ESP8266WiFi.h>
#include <WiFiClient.h>

char buf[10];
WiFiServer server(9000);

void setup() {
  Serial.begin(115200);
  delay(500);
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(IPAddress(10,10,10,10), IPAddress(10,10,10,10), IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00  
  WiFi.softAP("OUASSA RUTH", "qwer1234");
  pinMode(D3, OUTPUT);
  digitalWrite(D3, LOW);
  server.begin();

}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    if (client.connected()) {
      int n = client.read((unsigned char *)buf, 1);
      if (n > 0) {
        Serial.println(buf[0]);
        if (buf[0] == '0') {
          digitalWrite(D3, LOW);
        } else {
          digitalWrite(D3, HIGH);
        }
      }
    }
  }

}
