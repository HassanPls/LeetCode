/* Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int removed = 0;

        for (size_t i = 0; i < intervals.size(); i++)
        {
            for (size_t j = 0; j < intervals.size(); j++)
            {
                if (i == j) continue;

                int c = intervals[j][0];
                int d = intervals[j][1];
                int a = intervals[i][0];
                int b = intervals[i][1];

                if (c <= a && b <= d) {
                    removed++;
                    break;
                }
            }
            
        }

        return intervals.size() - removed;
        
    }
};