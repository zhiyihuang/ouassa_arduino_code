#include <ESP8266WiFi.h>

char buf[10];


void setup() {
  Serial.begin(9600);
   delay(1000);
   Serial.println("Client says hi");
   WiFi.begin("Light", "Let there be light");
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Waiting");
   }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void loop() {

 int l=analogRead(D3);
 //Serial.println(l);
  if (l >100) {
    strcpy(buf, "2");
  } else {
    strcpy(buf, "0");
      
    }
    
WiFiClient client; 
  if(client.connect("10.10.10.10", 9009)){
    client.write(buf, 1);
  //  Serial.println("1 byte sent");
    client.stop();

 
  }
 delay(100); 
}




    
