/* You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides. */

#include <vector>

class Solution {
public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        
        int minLandEnd = 2e9;
        for (size_t i = 0; i < landStartTime.size(); i++)
        {
            minLandEnd = std::min(minLandEnd, landStartTime[i] + landDuration[i]);
        }

        int minWaterEnd = 2e9;
        for (size_t i = 0; i < waterStartTime.size(); i++)
        {
            minWaterEnd = std::min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }

        int bestTime = 2e9;
        for (size_t i = 0; i < waterStartTime.size(); i++)
        {
            bestTime = std::min(bestTime, std::max(minLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        
        for (size_t i = 0; i < landStartTime.size(); i++)
        {
            bestTime = std::min(bestTime, std::max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        
        return bestTime;
    }
};