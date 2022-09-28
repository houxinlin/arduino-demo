#include <WiFi.h>

#define LED_PIN_NUMBER 2
#define AP_SSID "103灯"
#define AP_PSSWORD "103abcabc.."
#include <WebServer.h>
#define LED_PIN 33

WebServer  server(80);

void responseIndex() {
  server.send(200, "text/html", "<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'><title>103门禁</title></head><body> <a href='/open'>开门</a> <a href='/close'>关门</a></body></html>");
}
void httpOpen() {
   digitalWrite(LED_PIN,LOW);
  server.send(200, "text/html", "ok");

}

void httpClose() {
  
  server.send(200, "text/html", "ok");
  digitalWrite(LED_PIN,HIGH);
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
   WiFi.mode(WIFI_AP);
  pinMode(LED_PIN_NUMBER, OUTPUT);

  
  pinMode(LED_PIN, OUTPUT);    
  server.on("/", responseIndex);
  server.on("/open", httpOpen);
  server.on("/close", httpClose);
  server.begin();
  WiFi.softAP(AP_SSID, AP_PSSWORD);
  Serial.println("start.....");
  IPAddress myIP = WiFi.softAPIP();
  Serial.println(myIP);
}


void loop() {
  server.handleClient();
 }
