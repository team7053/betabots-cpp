#include <AutoCode.h>

void AutoCode::AutoPIDForwards()
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
void AutoCode::AutoVision()
{
    //
    turnFactor = robot.centerX - (RobotMap::cameraWidth / 2);
    robotDrive.setDrive(0, turnFactor * 0.005);
    dStation.ReportError("Alt 1 AutoCode Activated");
}
void AutoCode::AutoPIDStill()
{
    robotDrive.setDrive(0, pid.getPIDOutput());
    dStation.ReportError("Alt 2 AutoCode Activated");
}