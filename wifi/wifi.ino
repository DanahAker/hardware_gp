#include <WiFi.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "ake321";
const char* password = "Aker40";
AsyncWebServer server(80);
void setup(){
    Serial.begin(115200);
    delay(1000);

   
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    //Serial.println(WiFi.localIP());

   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "ESP32 Web Server");
  });

  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
    forward();
    request->send(200, "text/plain", "Moving Forward");
  });

  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
    backward();
    request->send(200, "text/plain", "Moving Backward");
  });

  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request){
    left();
    request->send(200, "text/plain", "Moving Left");
  });

  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request){
    right();
    request->send(200, "text/plain", "Moving Right");
  });

  // Start server
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
