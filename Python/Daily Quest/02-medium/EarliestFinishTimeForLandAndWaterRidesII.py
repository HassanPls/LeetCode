""" You are given two categories of theme park attractions: land rides and water rides.

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
Return the earliest possible time at which the tourist can finish both rides. """

class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:

        landEnds = min( s + d for s, d in zip(landStartTime, landDuration));
        waterEnds = min( s + d for s, d in zip(waterStartTime, waterDuration)); 

        bestTime = float('inf')
        for i,waterStart in enumerate(waterStartTime):
            bestTime = min(bestTime, max(waterStart, landEnds) + waterDuration[i]);

        for i, landStart in enumerate(landStartTime):
            bestTime = min(bestTime, max(landStart, waterEnds) + landDuration[i]);
        
        return bestTime