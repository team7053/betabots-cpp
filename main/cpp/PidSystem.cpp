#include <PidSystem.h>

PidSystem::PidSystem()
{
    pidSystem = new PIDController{RobotMap::pidP, RobotMap::pidI, RobotMap::pidD, gyro.navx, this};
    pidSystem->SetInputRange(RobotMap::pidMinInput, RobotMap::pidMaxInput);
    pidSystem->SetOutputRange(RobotMap::pidMinOutput, RobotMap::pidMaxOutput);
    pidSystem->SetAbsoluteTolerance(RobotMap::pidAbsTolerance);
    pidSystem->SetContinuous(true);
    pidSystem->SetSetpoint(0.0f);
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
void PidSystem::setSetpoint(double setpoint)
{
    pidSystem->SetSetpoint(setpoint);
}
double PidSystem::getSetpoint()
{
    return pidSystem->GetSetpoint();
}