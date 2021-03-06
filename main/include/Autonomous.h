#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include <Arm.h>
#include <Robot.h>
#include <Gyro.h>
#include <ObdUltrasonic.h>
#include <PidSystem.h>
#include <LED.h>
#include <RobotMap.h>
#include <Drivetrain.h>
#include <frc/DriverStation.h>

class Autonomous
{
public:
  Autonomous();
  ~Autonomous();
  void AutoPIDForwards();
  void AutoVision();
  void AutoPIDStill();

private:
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