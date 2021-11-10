#include <Arduino.h>
#include <StepMotor.h>
#include <MultiStepper.h>
#include <Order.h>

#define yMaxPin 6
#define yMinPin 7
#define xMaxPin 6
#define xMinPin 7

#define motorInterfaceType 1
const int stepPins[3] =  {1, 3, 5};
const int dirPins[3] = {0, 2, 4};


StepMotor step = StepMotor(motorInterfaceType, stepPins, dirPins);
Order order = Order();

void setup()
{
    order.connectWifi();
    int startingPos[2] = {0,0};
    step.setup(1000, 500, 500, startingPos);
    //step.calibrate(yMinPin, yMaxPin, xMinPin, xMaxPin);
}

void loop()
{
    order.getOrder();
    switch(order.mode) {
        case 10:
            ; // No new order
        case 0:
            ; // Ramen mode
        case 1:
            ; // Game mode
    }
}
