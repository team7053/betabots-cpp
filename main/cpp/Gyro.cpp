#include <Gyro.h>

Gyro::Gyro()
{
    navx = new AHRS{SPI::Port::kMXP};
    navx->Reset();
    navx->ZeroYaw();
}

double Gyro::getYawAngle()
{
    return navx->GetYaw();
}
bool Gyro::isConnected()
{
    return navx->IsConnected();
}
void Gyro::reset()
{
    navx->Reset();
}
void Gyro::zeroYaw()
{
    navx->ZeroYaw();
}