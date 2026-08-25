/* Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calcHourAngle(int hour, double minutes) {
        int hourCorrect = hour >= 12 ? hour - 12 : hour;        
        return (30 * hourCorrect) + (30 * (minutes/60));
    }

    double calcMinAngle(int minutes) {
        return 6 * minutes;
    }

    double angleClock(int hour, int minutes) {
        double valMod = abs(calcHourAngle(hour, minutes) - calcMinAngle(minutes));
        return valMod > 180 ? 360 - valMod : valMod;
    }
};