#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Hello World");
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin("NetComm Wireless 3874", "Dozuqehogu");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.println("WiFi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

int last_switch, current_switch;
int led_state=0;
int remember_num = 320;
WiFiClient client;

void loop() {
  int s = analogRead(A0);

  if (client.connect(IPAddress(192,168,20,100), 7000)) {
    Serial.println("Successful");
    float d = (float)s;
    client.write((unsigned char *)&d, 4);
    client.stop();
  }
  Serial.println(s);
  delay(2000);
  //if(s > remember_num-20) {
  //  digitalWrite(D3, HIGH);
  //}
  //else {
  //  digitalWrite(D3, LOW);
  //}
}
