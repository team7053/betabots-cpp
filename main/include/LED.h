#ifndef LED_H
#define LED_H

#include <frc/Spark.h>
#include <RobotMap.h>

class LED
{
public:
  LED(int ledCh);
  void setLEDRedHeartbeat();
  void setLEDBlueHeartbeat();
  void setLEDRedSolid();
  void setLEDBlueSolid();

private:
  frc::Spark ledController;
};

#endif