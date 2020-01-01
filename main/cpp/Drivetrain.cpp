#include <Drivetrain.h>

Drivetrain::Drivetrain(int ml, int mr) : lm(ml),
                                         rm(mr),
                                         drive(lm, rm)
{
}

void Drivetrain::setDrive(double fwd, double turn)
{
    drive.ArcadeDrive(fwd, turn);
}
bool Drivetrain::isMoving()
{
    if (lm.Get() > 0.2 || lm.Get() < -0.2 || rm.Get() > 0.2 || rm.Get() < -0.2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
