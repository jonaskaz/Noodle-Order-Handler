#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include <ezButton.h>


class StepMotor : public MultiStepper
{
public:
    StepMotor(int motorInterfaceType, const int stepPins[3], const int dirPins[3]);
    AccelStepper stepper1;
    AccelStepper stepper2;
    AccelStepper stepper3;
    MultiStepper steppers;
    void calibrate(int yMinPin, int yMaxPin, int xMinPin, int xMaxPin);
    void goTo(int posx, int posy);
    int * getPos();
    void setup(int maxSpeed, int accelx, int accely, int startPos[2]);
private:
    int xMax;
    int yMax;
    int xMin;
    int yMin;
    void setupHelper(AccelStepper stepper, int maxSpeed, int accel, int startPos);
    long * mapPercentToPos(int percentx, int percenty);
    int * mapPosToPercent(int posx, int posy);
    float * getPercentSteps();
};
