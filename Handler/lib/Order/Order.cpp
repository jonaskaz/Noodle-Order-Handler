#include <Order.h>

void Order::connectWifi()
{
    WiFi.begin(this->SSID, this->PWD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}

void Order::getOrder()
{
    this->http.begin(this->client, this->url);
    int httpCode = this->http.GET();
    String payload;
    if (httpCode == HTTP_CODE_OK)
    {
        payload = this->http.getString();
        parseOrder(payload);
    }
}

void Order::parseOrder(String payload)
{
    DeserializationError error = deserializeJson(doc, payload);
    if (error)
    {
        return;
    }
    if (!(doc.containsKey("mode")))
    {
        mode = 10;
        return;
    }
    mode = doc["mode"];
    flavor = doc["flavor"];
    toppings = doc["toppings"];
}

void Order::sendOrder()
{
    Serial.print(this->mode);
    Serial.println(this->flavor);
    serializeJson(this->toppings, Serial);
    Serial.println();
}
