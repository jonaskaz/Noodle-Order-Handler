#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <ArduinoJson.h>


class Order 
{
public:
    void connectWifi();
    void getOrder();
    const char* url = "http://cupnoodle-api.herokuapp.com/order";
    WiFiClient client;
    HTTPClient http;
private:
    const char* SSID = "OLIN-DEVICES";
    const char* PWD = "Design&Fabric8";
    StaticJsonDocument<200> doc;
    int mode;
    const char* flavor;
    JsonArray toppings;
    void parseOrder(String payload);
};