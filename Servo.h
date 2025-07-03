#pragma once

class Servo {
    double angle;
    double target;
    double stepSize;
public:
    Servo();
    void moveTo(double targetAngle);
    void step();
    double getAngle() const;
    bool atTarget() const;
};