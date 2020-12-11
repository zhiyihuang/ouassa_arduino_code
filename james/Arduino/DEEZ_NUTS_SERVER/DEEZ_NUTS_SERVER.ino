#include <ESP8266WiFi.h>
unsigned char buf[10];

WiFiServer server(9000);

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  Serial.println("YOU ARE CONNECTED TO 'deez nuts'");
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(IPAddress(10, 10, 10, 10), 
         IPAddress(10, 10, 10, 10), IPAddress(255, 255, 255, 0));
  WiFi.softAP("ITS YA BOI", "skinny pp");
  
  server.begin();
}

void loop() {                                  
 WiFiClient client = server.available();
 

 if (client) {
  int n = client.read(buf, 1);
  if (n > 0) {
    Serial.println(buf[0]);
    if(buf[0] == '0') {
      digitalWrite(D4, HIGH);    
      digitalWrite(D2, HIGH);
      delay(300);
      digitalWrite(D4, LOW);    
      digitalWrite(D2, LOW);
      delay(300);
      digitalWrite(D4, HIGH);    
      digitalWrite(D2, HIGH);
      delay(300);
      digitalWrite(D4, LOW);    
      digitalWrite(D2, LOW);
      delay(300);
      digitalWrite(D3, HIGH);
      delay(300);
      digitalWrite(D3, LOW);
      delay(300);
      digitalWrite(D3, HIGH);
      delay(300);
      digitalWrite(D3, LOW);
      delay(300);
    }
    else {
      digitalWrite(D4, HIGH);
      delay(200);
      digitalWrite(D3, HIGH);
      delay(200);
      digitalWrite(D2, HIGH);
      delay(200);
      digitalWrite(D4, LOW);
      delay(200);
      digitalWrite(D3, LOW);
      delay(200);
      digitalWrite(D2, LOW);
      delay(200);
      
    }
  }
 }
}
