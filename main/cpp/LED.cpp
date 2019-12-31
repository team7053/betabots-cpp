#include <LED.h>

LED::LED(int ledCh) : ledController(ledCh)
{
}

void LED::setLEDBlueSolid()
{
    LED::ledController.Set(RobotMap::LEDBlueSolid);
}
void LED::setLEDBlueHeartbeat()
{
    LED::ledController.Set(RobotMap::LEDBlueHeartbeat);
}
void LED::setLEDRedSolid()
{
    LED::ledController.Set(RobotMap::LEDRedSolid);
}
void LED::setLEDRedHeartbeat()
{
    LED::ledController.Set(RobotMap::LEDRedHeartbeat);
}