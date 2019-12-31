#include <PidSystem.h>

PidSystem::PidSystem()
{
    pidSystem = new PIDController{RobotMap::pidP, RobotMap::pidI, RobotMap::pidD, gyro.navx, this};
    pidSystem->SetInputRange(RobotMap::pidMinInput, RobotMap::pidMaxInput);
    pidSystem->SetOutputRange(RobotMap::pidMinOutput, RobotMap::pidMaxOutput);
    pidSystem->SetAbsoluteTolerance(RobotMap::pidAbsTolerance);
    pidSystem->SetContinuous(true);
    pidSystem->SetSetpoint(RobotMap::pidSetpoint);
}

void PidSystem::PIDWrite(double output)
{
    this->rotateRate = output;
}

double PidSystem::getError(double sp, double ang)
{
    return abs(ang - sp);
}
void PidSystem::enablePID()
{
    pidSystem->Enable();
}
void PidSystem::disablePID()
{
    pidSystem->Disable();
}
double PidSystem::getPIDOutput()
{
    return rotateRate;
}