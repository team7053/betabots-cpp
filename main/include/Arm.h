#ifndef ARM_H
#define ARM_H
#include <frc/Servo.h>
#include <frc/Spark.h>

class Arm
{
  public:
    Arm(int mp, int sp);
    void setArmSpeed(double spd);
    void setDumperPosition(double pos);

  private:
    frc::Spark armMotor;
    frc::Servo armServo;
};

#endif