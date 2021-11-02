#include "StepMotor.h"

StepMotor::StepMotor(int motorInterfaceType, int stepPin, int dirPin) : AccelStepper(motorInterfaceType, stepPin, dirPin) {}

void StepMotor::setup(int maxSpeed, int accel, int startPos = 0)
{
    this->setAcceleration(accel);
    this->setMaxSpeed(maxSpeed);
    this->setCurrentPosition(startPos);
}

void StepMotor::calibrate()
{
    this->setCurrentPosition(0);
    // TODO
    //  The below variables will keep track of the start and end of the rail system
    //  These values should be calculated from our calibration
    this->startPos = -1000;
    this->endPos = 1000;
}

void StepMotor::run(int speed)
{
    this->setSpeed(speed);
    this->runSpeed();
}

void StepMotor::goTo(int percent)
{
    int pos = mapPercentToPos(percent);
    this->moveTo(pos);
    this->runToPosition();
}

int StepMotor::getPos()
{
    return this->currentPosition();
}

int StepMotor::mapPercentToPos(int percent)
{
    int range = startPos - endPos;
    int step = range / 100;
    return (int) step * percent;
}