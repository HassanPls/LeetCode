/* You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int validSubarrayCount = 0;

        int index = 0;
        for (size_t i = 0; i < n; i++)
        {
            int targetCounting = 0;
            for (size_t j = i; j < n; j++)
            {
                if (nums[j] == target) {
                    targetCounting++;
                }

                int subarrayLength = j - i + 1;

                if (targetCounting > 0.5 * subarrayLength) {
                    validSubarrayCount++;
                }
            }
        }

        return validSubarrayCount;
    }
};