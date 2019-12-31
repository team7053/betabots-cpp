#ifndef OBDULTRASONIC_H
#define OBDULTRASONIC_H
#include <frc/Ultrasonic.h>
#include <RobotMap.h>

class ObdUltrasonic
{
  public:
    ObdUltrasonic(int pc, int ec);
    double getUltrasonicRange();

  private:
    frc::Ultrasonic ultra;
    int ultraReadings[RobotMap::numReadings] = {};
    double readingAverage;
    int readIndex;
    int total;
};

#endif