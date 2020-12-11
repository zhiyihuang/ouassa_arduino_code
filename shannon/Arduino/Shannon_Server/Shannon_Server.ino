#include <ESP8266WiFi.h>

WiFiServer server(9009);

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Hello World");
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(
    IPAddress(10,10,10,10), 
    IPAddress(10,10,10,10), 
    IPAddress(255,255,255,0));
  WiFi.softAP("Light", "Let there be light");
  server.begin();
  Serial.println("Server up");
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
}

unsigned char buf[1];

void loop() {
WiFiClient client = server.available();

  if (client > 0) {
    if (client == 1) {
     int n = client.read(buf, 1);
     if (n == 1) {
       if(buf[0] == '0') {
        digitalWrite(D3, HIGH);
        delay(250);
        digitalWrite(D3, LOW);
        digitalWrite(D2, HIGH);
        delay(250);
        digitalWrite(D2, LOW);
        digitalWrite(D1, HIGH);
        delay(250);
        digitalWrite(D1, LOW);
       }
       else {
        digitalWrite(D1, HIGH);
        delay(250);
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        delay(250);
        digitalWrite(D2, LOW);
        digitalWrite(D3, HIGH);
        delay(250);
        digitalWrite(D3, LOW);
       }
     }  if (client == 2) {
     int n = client.read(buf, 1);
     if (n > 2) {
      if(buf[0] == '0') {
        digitalWrite(D3, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D1, HIGH);
        delay(250);
        digitalWrite(D3, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D1, LOW);
       }
       else {
        digitalWrite(D3, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D1, LOW);
        delay(250);
        digitalWrite(D3, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D1, HIGH);
       }
     }
    }
  }

  }
  else {
    digitalWrite(D3, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D1, LOW);
    delay(1000);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
  }
}
