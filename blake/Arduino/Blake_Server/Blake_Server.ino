#include <ESP8266WiFi.h>

WiFi.Server(9009);

void setup() {
Serial.begin(9600);
delay(500);
Serial.println("its ya boy");
WiFi.mode(WIFI_AP_STA);
WiFi.softAPConfig(IPAddress(10,10,10,10), IPAddress(10,10,10,10), IPAddress(255,255,255,0));
WiFi.softAP("Not keen for talks", "qwer1234");
server.begin(); 

}

void loop() {
WiFiClient=server.available();

if(client !=null){
    int n = client.read(buf, 1);
    if(n > 0) {
      if(buf[0] == '0') digitalWrite(D3, LOW);
      else digitalWrite(D3,HIGH);
    }
}

}
