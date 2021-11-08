#include <Arduino.h>
#include <StepMotor.h>
#include <Order.h>


#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1


StepMotor stepper = StepMotor(motorInterfaceType, stepPin, dirPin);
Order order = Order();

void setup()
{
    order.connectWifi();
    stepper.setup(1000, 800, 0);
    stepper.calibrate();
}

void loop()
{
    order.getOrder();
    delay(5000);
    stepper.goTo(100);
    delay(1000);
    stepper.goTo(0);
    delay(1000);
}
