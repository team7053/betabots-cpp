#include <OI.h>

double OI::getRawX()
{
    return OI::joystick1.GetX();
}
double OI::getRawY()
{
    return OI::joystick1.GetY();
}
double OI::getLimitedX()
{
    double limitedX = (((((OI::joystick1.GetRawAxis(3) * (-1)) + 1) / 4) + 0.65) * OI::getRawX());
    return limitedX;
}
double OI::getLimitedY()
{
    double limitedY = ((((((OI::joystick1.GetRawAxis(3) * (-1)) + 1) / 4) + 0.5) * OI::getRawY()) * (-1));
    return limitedY;
}
double OI::getResetYaw()
{
    return joystick1.GetRawButton(RobotMap::resetYawButton);
}
bool OI::getSmallServoTurn()
{
    return joystick2.GetRawButton(RobotMap::smallServoButton);
}
bool OI::getBigServoTurn()
{
    return joystick2.GetRawButton(RobotMap::bigServoButton);
}
bool OI::getArmMotorLeft()
{
    return joystick2.GetRawButton(RobotMap::armMotorLeftButton);
}
bool OI::getArmMotorRight()
{
    return joystick2.GetRawButton(RobotMap::armMotorRightButton);
}
bool OI::getPidTeleopToggle()
{
    return joystick1.GetRawButton(RobotMap::togglePidTelopButton);
}