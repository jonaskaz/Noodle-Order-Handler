#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>


class Order 
{
public:
    void connectWifi();
    void getOrder();
    const char* url = "http://cupnoodle-api.herokuapp.com/order";
    void sendOrder();
    WiFiClient client;
    HTTPClient http;
    int mode;
    const char* flavor;
    JsonArray toppings;
private:
    const char* SSID = "OLIN-DEVICES";
    const char* PWD = "Design&Fabric8";
    StaticJsonDocument<200> doc;
    void parseOrder(String payload);
};