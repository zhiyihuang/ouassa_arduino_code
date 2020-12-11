#include <ESP8266WiFi.h>

unsigned char buf[10];
WiFiClient client;

void setup() {
 Serial.begin(9600);
 delay(500);
 Serial.println("Hello from Client");
 WiFi.begin("Caroline+Ruth","Caroline"); 
 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
 }
Serial.println("WiFi Connected");

}

void loop() {
  int l= analogRead(A0);

   if (l < 320) {
       strcpy ((char *)buf,"0");
   } else if (l > 500){
       strcpy ((char *)buf,"2");
   } else if (l >= 320 && l <= 500){
       strcpy ((char *)buf,"1");
   } else {
    
   }

   if(client.connect("10.10.10.10", 9000)){
    client.write(buf, 1);
    Serial.println("1 byte sent");
    int n = client.read(buf,2);
    if (n > 0) client.stop();
   }

}
