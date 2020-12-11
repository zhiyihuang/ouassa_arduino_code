#include <ESP8266WiFi.h>

unsigned char buf[10];

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  delay(500);
  Serial.println("Ready");
  pinMode(A0, INPUT);

  WiFi.begin("ITS YA BOI", "skinny pp");
  while (WiFi.status() !=  WL_CONNECTED) {
    delay(100);
    Serial.println(".");
    }
  Serial.println("WiFi Connected");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(A0);

  if (sensor > 700){
    strcpy((char *)buf, "0");
  }
  else {
    strcpy((char *)buf, "1");
  }

WiFiClient client;
  if(client.connect("10.10.10.10", 9000)){
    client.write(buf, 1);
    Serial.println(sensor);
    delay(50);
    client.stop();
  }
}
