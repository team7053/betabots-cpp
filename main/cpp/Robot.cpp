/*-------------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                           */
/* Open Source Software - may be modified and shared by FRC teams. The code      */
/* must be accompanied by the FIRST BSD license file in the root directory of    */
/* the project.                                                                  */
/*-------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------*/
/* C++ conversion of Betabots 2019 Labview Code (With Extra Gyro and PID system!)*/
/* (And with some mutherfucking Vision Processing (GRIP Pipeline) )              */
/* By: Nathan Salmard(FRC Team 7053, RoboHuskies)                                */
/* Last Update: 27/12/2019 (dd/mm/yyyy)                                          */
/*-------------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

Robot::Robot() : robotDrive(rMap.leftMotorChannel, rMap.rightMotorChannel),
                 ultra(rMap.pingChannel, rMap.echoChannel),
                 gyro(),
                 arm(rMap.armMotorChannel, rMap.armServoChannel),
                 led(rMap.ledChannel),
                 pid()
{
}

//This creates a seperate thread for vision processing to runn along side the main thread
void Robot::VisionThread()
{
  // Creates the UsbCamera object and starts a automatic Mjpeg feed to the Dashboard
  cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture("Camera 1", RobotMap::cameraPort1);
  camera.SetResolution(RobotMap::cameraWidth, RobotMap::cameraHeight);
  //Creates a sourceMat for the grip process
  cs::CvSink inputStream = CameraServer::GetInstance()->GetVideo("Camera 1");
  //Sets up the output processed stream
  cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Processed Feed", 640, 480);
  //Creates a Matrix object to which the inputStream will be converted to
  cv::Mat sourceMat;
  bool isVisionProcessEnabled;
  if (inputStream.GrabFrame(sourceMat) == 0)
  {
    frc::DriverStation::ReportError("Vision Processing Error");
    isVisionProcessEnabled = false;
  }
  else
  {
    isVisionProcessEnabled = true;
    grip::GripPipeline grip = grip::GripPipeline();
    while (true)
    {
      inputStream.GrabFrame(sourceMat);
      grip.Process(sourceMat);
      CvRect r = cvBoundingRect(grip.GetFilterContoursOutput());
      robot.centerX = r.x + (r.width / 2);
      cv::Mat *outputMat = grip.GetMaskOutput();
      outputStreamStd.PutFrame(*outputMat);
    }
  }
}

// this function is run once at startup
void Robot::RobotInit()
{
  // Creates a runtime timer and starts it
  autoTimer = new Timer();
  autoTimer->Start();
  // Sets default boolean for the Ultrasonic and NavX connection indicators on the Dashboard to false
  frc::SmartDashboard::PutBoolean("Ultra Connection", false);
  frc::SmartDashboard::PutBoolean("Gyro Connection", false);
  // Puts the kAutoNameArray into the Auto Selector Combo box
  frc::SmartDashboard::PutStringArray("Auto List", kAutoNameArray);
  frc::SmartDashboard::PutStringArray("Alliance List", kAllianceArray);
  // Sets the value of allianceSelected to the selection of the Alliance Selector combo box
  allianceSelected = SmartDashboard::GetString("Alliance Selector", kAllianceRed);
  // Sets the value of autoSelected to the selection of the dropdown menu on the Dashboard
  autoSelected = SmartDashboard::GetString("Auto Selector", kAutoNameDefault);
  std::thread visionThread(VisionThread);
  visionThread.detach();
}

//This function is called every robot packet, no matter the mode.
void Robot::RobotPeriodic()
{

  if (allianceSelected == kAllianceBlue)
  {
    led.setLEDRedHeartbeat();
  }
  else
  {
    led.setLEDBlueHeartbeat();
  }
  ultraRange = ultra.getUltrasonicRange();
  frc::SmartDashboard::PutNumber("Ultra", ultraRange);
  // Sets yawAngle to the yaw value of the NavX
  yawAngle = gyro.getYawAngle();
  // Checks if the navx is connected
  if (gyro.isConnected())
  {
    frc::SmartDashboard::PutNumber("Gyro", yawAngle);
    frc::SmartDashboard::PutBoolean("Gyro Connection", false);
  }
  else
  {
    frc::SmartDashboard::PutBoolean("Gyro Connection", true);
    frc::SmartDashboard::PutNumber("Gyro", yawAngle);
  }
}

void Robot::AutonomousInit()
{

  // Resets and starts the runtime timer
  autoTimer->Reset();
  autoTimer->Start();
  pid.enablePID();
}

void Robot::AutonomousPeriodic()
{
  frc::SmartDashboard::PutNumber("Error", pid.getError(rMap.pidSetpoint, gyro.getYawAngle()));
  if (autoSelected == kAutoNameDefault)
  {

    if (ultraRange >= 30.0)
    {
      robotDrive.setDrive(0.5, pid.getPIDOutput());
      // This is done for debugging purposes because VS is a bitch and won't do std::cout because fuck the user
      frc::DriverStation::ReportError("Forwards");
    }
    else
    {
      robotDrive.setDrive(0, pid.getPIDOutput());
      // This is done for debugging purposes because VS is a bitch and won't do std::cout because fuck the user
      frc::DriverStation::ReportError("Stop");
    }
  }
  else if (autoSelected == kAutoNameAlt1)
  {
    robotDrive.setDrive(0, pid.getPIDOutput());
    // This is done for debugging purposes because VS is a bitch and won't do std::cout because fuck the user
    frc::DriverStation::ReportError("PID ENABLED. NOW KICK THE ROBOT");
  }
  else
  {
  }
}

// Runs once before TeleopPeriodic
void Robot::TeleopInit()
{
  pid.disablePID();
}

// This function is called every robot packet if the mode selected is Teleop and after TeleopInit has been run once
void Robot::TeleopPeriodic()
{
  robotDrive.setDrive(oi.getLimitedY(), oi.getLimitedX());
  //button 1(small) and 2(big) to control dump servo
  if (oi.getSmallServoTurn())
  {
    arm.setDumperPosition(rMap.smallServoValue);
  }
  else if (oi.getBigServoTurn())
  {
    arm.setDumperPosition(rMap.bigServoValue);
  }
  //7(left) & 8(right) to control arm motor
  else if (oi.getArmMotorLeft())
  {
    arm.setArmSpeed(rMap.armMotorLeftValue);
  }
  else if (oi.getArmMotorRight())
  {
    arm.setArmSpeed(rMap.armMotorRightValue);
  }
  else if (oi.getResetYaw())
  {
    gyro.zeroYaw();
    gyro.reset();
  }
  else
  {
    arm.setArmSpeed(0);
    arm.setDumperPosition(rMap.defaultServoValue);
  }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
