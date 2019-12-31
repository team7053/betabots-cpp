#ifndef GYRO_H
#define GYRO_H
#include <AHRS.h>
#include <frc/PIDOutput.h>
#include <frc/PIDController.h>

class Gyro
{
  public:
    Gyro();
    double getYawAngle();
    bool isConnected();
    void reset();
    void zeroYaw();
    AHRS *navx;
};

#endif