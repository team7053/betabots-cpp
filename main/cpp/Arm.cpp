#include <Arm.h>

Arm::Arm(int mp, int sp) : armMotor(mp),
                           armServo(sp)
{
}
void Arm::setArmSpeed(double spd)
{
    Arm::armMotor.Set(spd);
}
void Arm::setDumperPosition(double pos)
{
    Arm::armServo.Set(pos);
}