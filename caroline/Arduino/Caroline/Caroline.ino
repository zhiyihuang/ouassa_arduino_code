#include <ESP8266WiFi.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  Serial.begin(115200);
  delay(500);
  //Serial.println("Hello World");
  pinMode(D3, OUTPUT);
  pinMode(A0,INPUT);

WiFi.mode(WIFI_STA);
WiFi.begin("NetComm Wireless 3874","Dozuqehogu"); 
while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("."); 
}
Serial.println("WiFi Connected");
Serial.print("IP address");
Serial.println(WiFi.localIP());
}
int last_switch, current_switch;
int led_state=0;
int rembered_num = 530;
WiFiClient client;
// the loop function runs over and over again forever
void loop() {
  
  int s = analogRead(A0);

if(client.connect(IPAddress(192,168,20,100), 7000)){
  Serial.println("successful");
  float d = (float)s;
  client.write((unsigned char *)&d, 4);
  client.stop();
}
 
 
Serial.println(s);
delay(500);
  //if(s < rembered_num-20) digitalWrite(D3, HIGH);
  //else digitalWrite(D3,LOW);
                    
}
