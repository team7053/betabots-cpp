#ifndef PIDSYSTEM_H
#define PIDSYSTEM_H

#include <frc/PIDController.h>
#include <frc/PIDOutput.h>
#include <frc/PIDSource.h>
#include <Gyro.h>
#include <RobotMap.h>

class PidSystem : public frc::PIDOutput
{
public:
  PidSystem();
  void PIDWrite(double output) override;
  double getPIDOutput();
  double getError(double sp, double ang);
  double getSetpoint();
  void enablePID();
  void disablePID();
  void setSetpoint(double setpoint);

private:
  Gyro gyro;
  frc::PIDController *pidSystem;

  double rotateRate;
};

#endif