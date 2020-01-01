#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <OI.h>
#include <RobotMap.h>
#include <frc/Spark.h>
#include <frc/drive/DifferentialDrive.h>

class Drivetrain
{
public:
  Drivetrain(int ml, int mr);
  void setDrive(double fwd, double turn);
  bool isMoving();

private:
  frc::Spark lm, rm;
  frc::DifferentialDrive drive;
};

#endif