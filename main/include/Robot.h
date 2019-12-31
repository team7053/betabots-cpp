/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <RobotMap.h>
#include <OI.h>
#include <Drivetrain.h>
#include <ObdUltrasonic.h>
#include <Gyro.h>
#include <Arm.h>
#include <LED.h>
#include <PidSystem.h>
#include <GripPipeline.h>
#include <frc/TimedRobot.h>
#include <frc/DriverStation.h>
#include <cameraserver/CameraServer.h>
#include <cscore_oo.h>
#include <iostream>
#include <AHRS.h>

using namespace frc;

class Robot : public TimedRobot
{
public:
  Robot();
  static void VisionThread();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  double centerX;

private:
  RobotMap rMap;
  OI oi;
  Drivetrain robotDrive;
  ObdUltrasonic ultra;
  Gyro gyro;
  Arm arm;
  LED led;
  grip::GripPipeline grip;
  PidSystem pid;
  Timer *autoTimer;
  frc::DriverStation *DS;

  double yawAngle;
  double ultraRange;
  double pidError;

  std::string autoSelected;
  std::string kAutoNameDefault = "Default";
  std::string kAutoNameAlt1 = "Alternative 1";
  std::string kAutoNameAlt2 = "Alternative 2";
  std::string kAutoNameArray[3] = {kAutoNameDefault, kAutoNameAlt1, kAutoNameAlt2};
  std::string allianceSelected;
  std::string kAllianceRed = "Red";
  std::string kAllianceBlue = "Blue";
  std::string kAllianceArray[2] = {kAllianceRed, kAllianceBlue};
};
