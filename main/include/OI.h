#ifndef OI_H
#define OI_H

#include <frc/Joystick.h>
#include <RobotMap.h>
class OI
{
public:
  double getLimitedY();
  double getLimitedX();
  double getRawY();
  double getRawX();
  double getResetYaw();
  bool getArmMotorLeft();
  bool getSmallServoTurn();
  bool getBigServoTurn();
  bool getArmMotorRight();
  bool getPidTeleopToggle();
  frc::Joystick joystick1{RobotMap::joystickChannel1};
  frc::Joystick joystick2{RobotMap::joystickChannel2};
};

#endif
