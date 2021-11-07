#include <Order.h>


void Order::connectWifi()
{
    Serial.begin(115200);
    WiFi.begin(this->SSID, this->PWD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("*");
    }
    Serial.println("");
    Serial.println("WiFi connection Successful");
    Serial.print(WiFi.localIP());
}

void Order::getOrder()
{
    Serial.println("Getting order");
    this->http.begin(this->client, this->url);
    int httpCode = this->http.GET();
    String payload;
    if (httpCode == HTTP_CODE_OK)
    {
        payload = this->http.getString();
        parseOrder(payload);
    }
    else
    {
        Serial.printf("[HTTP] GET... failed, error: %s\n", this->http.errorToString(httpCode).c_str());
    }
}

void Order::parseOrder(String payload)
{
    DeserializationError error = deserializeJson(doc, payload);
    Serial.println(payload);
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }
    mode = doc["mode"];
    flavor = doc["flavor"];
    toppings = doc["toppings"];
}

