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
