#include <ESP8266WiFi.h>


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  Serial.begin(115200);
  delay(500);
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin("NetComm Wireless 3874","Dozuqehogu");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.print("WIFI conneted ");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
}

int lastswitch=1, currentswitch;
int LEDstate=0;
int rememberedNum = 310;
WiFiClient client;
// the loop function runs over and over again forever
void loop() {
  
  int s = analogRead(A0);
  
  if(client.connect(IPAddress(192,168,20,100), 7000)){
    Serial.println("Successfully connected");
    float d = (float)s;
    client.write((unsigned char *)&d, 4);
    client.stop();
  }
  delay(2000);
  Serial.println(s);
  if(s < rememberedNum-12 && LEDstate == 0){
    digitalWrite(D3, HIGH);
    LEDstate = 1;
  }
  else {
    digitalWrite(D3, LOW);
    LEDstate = 0;
  }
  
}
