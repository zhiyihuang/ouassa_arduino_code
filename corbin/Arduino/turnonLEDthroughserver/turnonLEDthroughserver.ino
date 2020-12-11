#include <ESP8266WiFi.h>

IPAddress    apIP(10, 10, 10, 10);  // Defining a static IP address: local & gateway

/* This are the WiFi access point settings. Update them to your likin */
const char *ssid = "OUASSA CS";
const char *password = "qwer1234";
char buf[100];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);
  
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");

  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);
  }
  Serial.print(" Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;

  if (client.connect("10.10.10.10", 80)){
    int sensor = analogRead(A0);
    Serial.println(sensor);
    
    if(sensor > 700){
      strcpy(buf, "GET /?led=1 HTTP/1.1\r\nHOST: 10.10.10.10\r\nConnection: close\r\n\r\n");
    }
    else{
       strcpy(buf, "GET /?led=0 HTTP/1.1\r\nHOST: 10.10.10.10\r\nConnection: close\r\n\r\n");
    }
    client.write(buf, strlen(buf));
    client.stop();
  }
  delay(500)

}
