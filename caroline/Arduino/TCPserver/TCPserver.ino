#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Hardcode WiFi parameters as this isn't going to be moving around.
const char* ssid = "Ruth's Challenge to Dad";
const char* password = "Iamnothappy";
IPAddress    apIP(10, 10, 10, 10);  // Defining a static IP address: local & gateway

// Start a TCP Server on port 9000
WiFiServer server(9000);
char buf[101];

void setup() {
  Serial.begin(115200);
  pinMode ( D3, OUTPUT );

  //set-up the custom IP address
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00  
  
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  Serial.print(ssid);
  Serial.print(" ");
  Serial.println(password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  // Start the TCP server
  server.begin();
}

void loop() {
  // listen for incoming clients
 WiFiClient client = server.available();
  if (client){
    Serial.println("Client connected");
    if (client.connected()){
        // Read the incoming TCP stream
        //for(int i=0 ;i<101; i++) buf[i] = 0;
        int c = client.read((unsigned char *)buf, 6);
        if(c>0) {
          Serial.println(buf);
          if(buf[4] == '0') digitalWrite(D3, LOW);
          else digitalWrite(D3, HIGH);
        }
    }
  }
 }
