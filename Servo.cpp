#include "Servo.h"
#include <cmath>

Servo::Servo() : angle(90), target(90), stepSize(5) {}

void Servo::moveTo(double targetAngle) {
    if (targetAngle < 0) targetAngle = 0;
    if (targetAngle > 180) targetAngle = 180;
    target = targetAngle;
}

void Servo::step() {
    if (std::abs(angle - target) < stepSize)
        angle = target;
    else if (angle < target)
        angle += stepSize;
    else
        angle -= stepSize;
}

double Servo::getAngle() const {
    return angle;
}

bool Servo::atTarget() const {
    return std::abs(angle - target) < 1e-2;
}