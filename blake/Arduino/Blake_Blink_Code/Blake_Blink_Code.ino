
#include <ESP8266WiFi.h>
void setup() {
 

  Serial. begin(115200);
  delay(100);
  Serial.println("Ooga Booga");
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin("NetComm Wireless 3874", "Dozuqehogu");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

int last_switch, current_switch;
int led_state=0;
int rembered_num= 75;
WiFiClient client;
void loop() {
  
  int s = analogRead(A0);

  if(client.connect(IPAddress(192,168,20,100), 7000)){
    Serial.println("successful");
    float d = (float)s;
    client.write((unsigned char *)&d, 4);
    client.stop();
  }
delay(2000);
  Serial.println(s);
  //Serial.println(s); 
  if(s < rembered_num+15) digitalWrite(D3, HIGH);
  else digitalWrite(D3, LOW);

  
}
  
