#ifndef ROBOTMAP_H
#define ROBOTMAP_H

class RobotMap
{
public:
  const static int pingChannel = 8;
  const static int echoChannel = 9;

  const static int joystickChannel1 = 0;
  const static int joystickChannel2 = 1;

  const static int rightMotorChannel = 0;
  const static int leftMotorChannel = 1;

  const static int armMotorChannel = 2;
  const static int armServoChannel = 3;

  const static int ledChannel = 4;

  const static int numReadings = 20;

  const static int sliderAxis = 3;

  const static int smallServoButton = 1;
  constexpr static double smallServoValue = 0.175;
  const static int bigServoButton = 2;
  constexpr static double bigServoValue = 0.225;
  constexpr static double defaultServoValue = 0;

  const static int armMotorLeftButton = 7;
  constexpr static double armMotorLeftValue = 0.25;
  const static int armMotorRightButton = 8;
  constexpr static double armMotorRightValue = (-0.25);

  const static int togglePidTelopButton = 10;
  const static int resetYawButton = 11;

  constexpr static float LEDRedHeartbeat = 0.05;
  constexpr static float LEDBlueHeartbeat = 0.25;
  constexpr static float LEDRedSolid = 0.61;
  constexpr static float LEDBlueSolid = 0.87;

  const static int cameraPort1 = 1;
  const static int cameraFPS = 15;
  const static int cameraWidth = 320;
  const static int cameraHeight = 180;

  constexpr static float pidP = 0.5;
  constexpr static float pidI = 0.0;
  constexpr static float pidD = 0.1;
  constexpr static float pidMinInput = -180;
  constexpr static float pidMaxInput = 180;
  constexpr static float pidMinOutput = -0.4;
  constexpr static float pidMaxOutput = 0.4;
  constexpr static float pidAbsTolerance = 1.0;
};
#endif