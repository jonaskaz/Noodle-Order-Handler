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
    //TODO
    ;
}

int StepMotor::getPos() {
    return currentPosition();
}