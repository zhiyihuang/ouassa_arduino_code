//Connecting web server
#include <ESP8266WiFi.h>
char buf[100];

void setup(){

  Serial.begin(115200);
  delay(500);
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);

  WiFi.begin("OUASSA CS", "qwer1234");
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println("WiFi Connected");
}
WiFiClient client;

void loop(){
  
  if (client.connect("10.10.10.10", 80)){
    //read light sensor here
    int d = analogRead(A0);
    Serial.println(d);

    //send the HTTP request
    if(d > 300){
      //prepare HTTP request accordingly with led=1 or led=0
      strcpy(buf, "GET /?led=1 HTTP/1.1\r\nHost: 10.10.10.10\r\nConnection:close\r\n\r\n");
    } else {
      strcpy(buf, "GET /?led=0 HTTP/1.1\r\nHost: 10.10.10.10\r\nConnection:close\r\n\r\n");
    }
    delay(100);

      client.write(buf, strlen(buf));
      client.stop();
  }

}
