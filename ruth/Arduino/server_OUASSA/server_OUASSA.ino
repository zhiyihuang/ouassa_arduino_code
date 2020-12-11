#include <ESP8266WiFi.h>

WiFiServer server(9000);
unsigned char buf[10];

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(D3, OUTPUT); //red light
  pinMode(D1, OUTPUT); //green light
  pinMode(D5, OUTPUT); //yellow light
  digitalWrite(D3, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D5, HIGH);
  Serial.println("Hello from Server");
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(IPAddress(10,10,10,10), 
      IPAddress(10,10,10,10), IPAddress(255,255,255,0));
  WiFi.softAP("Caroline+Ruth","Caroline");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    int n = client.read(buf, 1);
    
    if( n > 0 ) {
      Serial.printf("%c\n", buf[0]);
      if(buf[0] == '0') {
        digitalWrite(D1, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D5, HIGH);
      } else if (buf[0] == '1') {
        digitalWrite(D3, HIGH);
        digitalWrite(D1, LOW);
        digitalWrite(D5, LOW);
        delay(50);
        digitalWrite(D3, LOW);
        digitalWrite(D1, HIGH);
        digitalWrite(D5, LOW);
        delay(100);
        digitalWrite(D3, LOW);
        digitalWrite(D1, LOW);
        digitalWrite(D5, HIGH);
        delay(100);
        //client.write("OK", 2);
        
      } else if (buf[0] == '2') {
        //client.write("OK", 2);
          digitalWrite(D1, LOW);
          digitalWrite(D3, LOW);
          digitalWrite(D5, HIGH);
          delay(100);
          digitalWrite(D1, LOW);
          digitalWrite(D3, LOW);
          digitalWrite(D5, HIGH);
          delay(100);
          digitalWrite(D1, LOW);
          digitalWrite(D3, HIGH);
          digitalWrite(D5, LOW);
          delay(100);
         
      } else {
        
      }
    }
  }

}
