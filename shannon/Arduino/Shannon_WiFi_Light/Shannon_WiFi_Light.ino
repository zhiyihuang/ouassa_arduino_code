#include <ESP8266WiFi.h>

void setup() {
  
  Serial.begin(115200);
  delay(500);
  Serial.println("Hello World");

  pinMode(A0, INPUT);

  //WiFi.mode(WIFI_STA);
  WiFi.begin("OUASSA CS", "qwer1234");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");

}

int threshold = 300;
char buf[100];
WiFiClient client;

void loop() {
  
  Serial.println("Connecting to Server");
  int d = analogRead(A0);
  Serial.println(d);
  
  if (client.connect("10.10.10.10", 80)) {

    Serial.println("Sending");
    
    if (d > threshold) {
      strcpy(buf, "GET /?led=1 HTTP/1.1\r\nHost: 10,10,10,10\r\nConnection: close\r\n\r\n");
    }
    else {
      strcpy(buf, "GET /?led=0 HTTP/1.1\r\nHost: 10,10,10,10\r\nConnection: close\r\n\r\n");
    }

    client.write(buf, strlen(buf));
    client.stop();
    
  }
  delay(500);
}
