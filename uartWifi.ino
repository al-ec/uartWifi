#include <ESP8266WiFi.h>            
#include <ESP8266WebServer.h>

const char *ssid = "uartWifi";
const char *password = "foobar123";
int x;
String str;

ESP8266WebServer server(80);

void setup() {
Serial.begin(115200);
WiFi.softAP(ssid, password);
server.on("/", handleRoot);
server.on("/send", handleTx);   //Associate the handler function to the path
server.begin();
}

void handleTx() { 
String message = "";
if (server.arg("send")== ""){
message = "Nothing to send!";
}else{
message = "Sent = ";
message += server.arg("send");
Serial.println(server.arg("send"));
}
server.send(200, "text/plain", message);
}

void handleRoot() {
String message = "";
String message = "Recieved: " + str;
server.send(200, "text/plain", message);
}

void loop() {
server.handleClient();
 if(Serial.available() > 0)
    {
        str = Serial.readStringUntil('\n');
        x = Serial.parseInt();
    }
}
