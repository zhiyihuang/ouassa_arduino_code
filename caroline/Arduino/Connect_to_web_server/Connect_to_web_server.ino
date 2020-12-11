#include <ESP8266WiFi.h>
char buf[100];

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  delay(500);
  //Serial.println("Hello World");
  pinMode(D3, OUTPUT);
  pinMode(A0,INPUT); 

WiFi.begin("OUASSA CS","qwer1234"); 
while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("."); 
}   
Serial.println("Connecting to web server");
}
WiFiClient client;

void loop() {
  // put your main code here, to run repeatedly:
if (client.connect("10.10.10.10", 80)){
  //read light sesnor here
  int d = analogRead(A0);

  //send HTTP request
if(d > 300) {
   // prepare HTTP request accordingly with led=1 or led=0
  strcpy(buf,"GET /?led=1 HTT/1.1\r\nHost: 10.10.10.10\r\nConnection: close\r\n\r\n");
} else {
  strcpy(buf, "GET /?led=0 HTT/1.1\r\nHost: 10.10.10.10\r\nConnection: close\r\n\r\n");
}

  client.write(buf, strlen(buf));
  client.stop();
}
}
