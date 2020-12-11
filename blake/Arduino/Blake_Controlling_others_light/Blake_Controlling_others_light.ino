#include <ESP8266WiFi.h>
char buf[100];
WiFiClient client;

void setup() {

 Serial.begin(115200);
 delay(100);
 pinMode(D3, OUTPUT);
 pinMode(A0,INPUT);
 
WiFi.begin("Let there be light", "Light");
 while (WiFi.status() !=WL_CONNECTED){
  delay (1000);
  Serial.print(".");
}
Serial.println("connected");


Serial.println("Connecting to web server");
}

void loop(){

if (client.connect("10.10.10.10", 80)) {
  int l =analogRead(A0);

  Serial.println(l);

  if(l >100){
    strcpy(buf, "GET /?led=1 HTTP/1.1\r\nHost: 10.10.10.10\r\nConnection: close\r\n\r\n");
  } else{
    strcpy(buf, "GET /?led=0 HTTP/1.1\r\nHost: 10.10.10.10\r\nConnection: close\r\n\r\n");
  }

client.write(buf,strlen(buf));
client.stop();
}
  
  

}
