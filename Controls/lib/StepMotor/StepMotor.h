#include <Arduino.h>
#include <AccelStepper.h>


class StepMotor : public AccelStepper
{
public:
    StepMotor(int motorInterfaceType, int stepPin, int dirPin);
    void calibrate();
    void goTo(int pos);
    int getPos();
    void run(int speed);
    void setup(int maxSpeed, int accel, int startPos = 0);
private:
    int mapPercentToPos(int pos);
    int endPos;
    int startPos;
};
