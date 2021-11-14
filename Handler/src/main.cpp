#include <Arduino.h>
#include <Order.h>

Order order = Order();

void setup()
{
    Serial.begin(112500);
    order.connectWifi();
    delay(5000);
}

void loop()
{
    order.getOrder();
    switch (order.mode) {
        case 10: // No new order
            break;
        case 0: // Ramen Mode
            order.sendOrder();
            while (Serial.available() == 0) {}
            break;
        case 1: // Game mode
            order.sendOrder();
            while (Serial.available() == 0) {}
            break;
    }
    delay(5000);
}
