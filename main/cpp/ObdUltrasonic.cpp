#include <ObdUltrasonic.h>

ObdUltrasonic::ObdUltrasonic(int pc, int ec) : ultra(pc, ec)
{
    readIndex = 0;
    readingAverage = 0;
    total = 0;
    for (int thisReading; thisReading < RobotMap::numReadings; thisReading++)
    {
        ultraReadings[thisReading] = 0;
    }
    ultra.SetAutomaticMode(true);
}

double ObdUltrasonic::getUltrasonicRange()
{
    total = total - ultraReadings[readIndex];          //Substract reading from the total
    ultraReadings[readIndex] = ultra.GetRangeInches(); //replaces said reading with new reading from ultrasonic sensor
    total = total + ultraReadings[readIndex];          //adds new reading to total
    readIndex = readIndex + 1;                         // moves readIndex to the next entry in the array
    if (readIndex >= RobotMap::numReadings)            //if readIndex reaches to the end of the array, set readIndex back to the start
    {
        readIndex = 0;
    }
    readingAverage = total / RobotMap::numReadings;
    return readingAverage;
}
