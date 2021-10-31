#include "StepMotor.h"


StepMotor::StepMotor(int motorInterfaceType, int stepPin, int dirPin) : AccelStepper(motorInterfaceType, stepPin, dirPin) {}

void StepMotor::calibrate() {
    setCurrentPosition(0); // This is an inherited method
    //TODO
    // The below variables will keep track of the start and end of the rail system
    // These values should be calculated from our calibration
    
    this -> startPos = -200;
    this -> endPos = 321;
}

void StepMotor::goTo(int pos) {
    int mappedPos = mapPos(pos);
    // mappedPos should be a number between startPos and endPos
    //TODO
    ;
}

int StepMotor::getPos() {
    return currentPosition();
}

int StepMotor::mapPos(int pos) {
    // TODO
    // pos will be an int between posMapMin and posMapMax
    // map this value onto a new scale from startPos to endPos
    // This makes it easy to call goTo(50) which should
    // bring us to the middle of the line
    return 0;
}