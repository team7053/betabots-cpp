#include <Autonomous.h>

void Autonomous::AutonomousDefault()
{
    if (ultra.getUltrasonicRange() >= 30.0)
    {
        robotDrive.setDrive(0.5, pid.getPIDOutput());
        // This is done for debugging purposes because VS is a bitch and won't do std::cout because fuck the user
        dStation.ReportError("Forwards");
    }
    else
    {
        robotDrive.setDrive(0, pid.getPIDOutput());
        // This is done for debugging purposes because VS is a bitch and won't do std::cout because fuck the user
        dStation.ReportError("Stop");
    }
}
void Autonomous::AutonomousAlt1()
{
    centerX = Robot::centerX;
    turn = centerX - (RobotMap::cameraWidth / 2);
    robotDrive.setDrive(0, turn);
    dStation.ReportError("Alt 1 Autonomous Activated");
}
void Autonomous::AutonomousAlt2()
{
    robotDrive.setDrive(0, pid.getPIDOutput());
    dStation.ReportError("Alt 2 Autonomous Activated");
}