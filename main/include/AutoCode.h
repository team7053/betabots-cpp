#ifndef AutoCode_H
#define AutoCode_H
#include <Arm.h>
#include <Robot.h>
#include <Gyro.h>
#include <ObdUltrasonic.h>
#include <PidSystem.h>
#include <LED.h>
#include <RobotMap.h>
#include <Drivetrain.h>
#include <frc/DriverStation.h>

class AutoCode
{

public:
  AutoCode();
  ~AutoCode();
  void AutoPIDForwards();
  void AutoVision();
  void AutoPIDStill();

private:
  Robot robot;
  RobotMap rMap;
  OI oi;
  Drivetrain robotDrive;
  ObdUltrasonic ultra;
  Gyro gyro;
  Arm arm;
  LED led;
  PidSystem pid;
  Robot robot;
  frc::DriverStation dStation;

  double turnFactor;
};

#endif