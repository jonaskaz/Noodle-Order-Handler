#include <Arduino.h>
#include <StepMotor.h>

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

StepMotor stepper = StepMotor(motorInterfaceType, stepPin, dirPin);

void setup()
{
    stepper.setup(1000, 500);
    stepper.calibrate();
}

void loop()
{
    stepper.goTo(100);
    delay(1000);
    stepper.goTo(0);
    delay(1000);
}
