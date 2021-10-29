#include <Arduino.h>
#include <AccelStepper.h>


class StepMotor : public AccelStepper
{
public:
    StepMotor(int motorInterfaceType, int stepPin, int dirPin);
    void calibrate();
    void goTo(int pos);
    int getPos();
private:
    int posMapMin = 0;
    int posMapMax = 0;
    int mapPos(int pos);
    int endPos;
    int startPos;
};
