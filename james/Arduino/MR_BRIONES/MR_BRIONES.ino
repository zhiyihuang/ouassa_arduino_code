#include <ESP8266WiFi.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  Serial.begin(115200);
  delay(500);
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);

WiFi.mode(WIFI_STA);
WiFi.begin("NetComm Wireless 3874", "Dozuqehogu");
while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
}
Serial.println("WiFi Connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}

int last_switch  = 1, current_switch;
int led_state = 0;
int r_num = 180;
WiFiClient client;

// the loop function runs over and over again forever
void loop() {
  int s = analogRead(A0);
  Serial.println(s);
if(client.connect(IPAddress(192,168,20,100), 7000)){
  Serial.println("successful");
  float d = (float)s;
  client.write((unsigned char *)&d, 4);
  client.stop();
}
delay(2000);

//if(s > r_num + 30) digitalWrite(D3, HIGH);
//else digitalWrite(D3, LOW);
  
} 

  //Serial.println(s);
  /* current_switch = s;
  if(current_switch == 0 && last_switch == 1){
    Serial.println("switch pressed");
    if (led_state == 0) {
      digitalWrite(D3, HIGH);
      led_state = 1;
    }
    else {
      digitalWrite(D3, LOW);
      led_state = 0;
    } 
  
  last_switch = current_switch;
  delay(50);*/
  //if(s == 0) digitalWrite(D3, HIGH);    // turn the LED on (HIGH is the voltage level)
  //else digitalWrite(D3, LOW);           // turn the LED off by making the voltage LOW
