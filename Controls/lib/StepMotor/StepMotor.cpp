#include "StepMotor.h"


StepMotor::StepMotor(int motorInterfaceType, const int stepPins[3], const int dirPins[3]){
    stepper1 = AccelStepper(motorInterfaceType, stepPins[0], dirPins[0]);
    stepper2 = AccelStepper(motorInterfaceType, stepPins[1], dirPins[1]);
    stepper3 = AccelStepper(motorInterfaceType, stepPins[2], dirPins[2]);
}

void StepMotor::setupHelper(AccelStepper stepper, int maxSpeed, int accel, int startPos)
{
    stepper.setAcceleration(accel);
    stepper.setMaxSpeed(maxSpeed);
    stepper.setCurrentPosition(startPos);
}

void StepMotor::setup(int maxSpeed, int accelx, int accely, int startPos[2])
{
    setupHelper(stepper1, maxSpeed, accelx, startPos[0]);
    setupHelper(stepper2, maxSpeed, accely, startPos[1]);
    setupHelper(stepper3, maxSpeed, accely, startPos[1]);
    steppers.addStepper(stepper1);
    steppers.addStepper(stepper2);
    steppers.addStepper(stepper3);
}

void StepMotor::calibrate(int yMinPin, int yMaxPin, int xMinPin, int xMaxPin)
{
    ezButton yMinLimit(yMinPin);
    ezButton yMaxLimit(yMaxPin);
    ezButton xMinLimit(xMinPin);
    ezButton xMaxLimit(xMaxPin);
    while (yMaxLimit.isReleased()) {
        long positions[3] = {0, 100000, 100000};
        steppers.moveTo(positions);
        steppers.run();
    }
    yMax = stepper2.currentPosition();
    while (yMinLimit.isReleased()) {
        long positions[3] = {0, -100000, -100000};
        steppers.moveTo(positions);
        steppers.run();
    }
    yMin = stepper2.currentPosition();
    while (xMinLimit.isReleased()) {
        long positions[3] = {-100000, yMin, yMin};
        steppers.moveTo(positions);
        steppers.run();
    }
    xMin = stepper1.currentPosition();
    while (xMaxLimit.isReleased()) {
        long positions[3] = {100000, yMin, yMin};
        steppers.moveTo(positions);
        steppers.run();
    }
    xMax = stepper1.currentPosition();
}

void StepMotor::goTo(int percentx, int percenty)
{
    long * pos = mapPercentToPos(percentx, percenty);
    pos[2] = pos[1];
    steppers.moveTo(pos);
    steppers.run();
}

int * StepMotor::getPos()
{
    return mapPosToPercent(stepper1.currentPosition(), stepper2.currentPosition());
}

long * StepMotor::mapPercentToPos(int percentx, int percenty)
{
    static long positions[2];
    float * steps = getPercentSteps();
    positions[0] = steps[0] * percentx;
    positions[1] = steps[1] * percenty;
    return positions;
}

float * StepMotor::getPercentSteps()
{
    int rangex = xMax - xMin;
    int rangey = yMax - yMin;
    float stepx = rangex / 100;
    float stepy = rangey / 100;
    static float steps[2] = {stepx, stepy};
    return steps;
}

int * StepMotor::mapPosToPercent(int posx, int posy)
{
    static int percentages[2];
    float * steps = getPercentSteps();
    percentages[0] = (int) posx/steps[0];
    percentages[1] = (int) posy/steps[1];
    return percentages;
}