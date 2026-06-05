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

#First try
class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:
        bestTime = 100000

        for h in range(2):
            if (h == 0):
                for i, landStart in enumerate(landStartTime):
                    landTotalTime = landStart + landDuration[i]

                    for j, waterStart in enumerate(waterStartTime):
                        time = landTotalTime
                        if landTotalTime < waterStart:
                            time += (waterStart - landTotalTime)
                        
                        time += waterDuration[j]

                        if (bestTime > time): bestTime = time
            else:
                for i, waterStart in enumerate(waterStartTime):
                    waterTotalTime = waterStart + waterDuration[i]

                    for j, landStart in enumerate(landStartTime):
                        time = waterTotalTime
                        if waterTotalTime < landStart:
                            time += (landStart - waterTotalTime)
                        
                        time += landDuration[j]

                        if (bestTime > time): bestTime = time
        
        return bestTime