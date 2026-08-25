#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int total = 0, maxTotal = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) {
                total = 0;
            } else {
                total++;
            }

            maxTotal = max(total, maxTotal);
        }
        
        maxTotal = max(total, maxTotal);
        
        return maxTotal;
    }
};