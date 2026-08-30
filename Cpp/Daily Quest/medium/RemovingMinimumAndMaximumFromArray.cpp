#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        vector<pair<int, int>> numsIdx(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            numsIdx[i] = {nums[i], i};
        }
              
        sort(numsIdx.begin(), numsIdx.end());

        int minIdx = numsIdx[0].second, maxIdx = numsIdx[nums.size() - 1].second;

        int total = 0;

        if (nums.size() - 1 - minIdx < minIdx) {
            total += nums.size() - minIdx;
        } else {
            total += minIdx + 1;
        }

        if (nums.size() - 1 - maxIdx < maxIdx) {
            total += nums.size() - maxIdx;
        } else {
            total += maxIdx + 1;
        }

        int sides = nums.size() + 1;

        if (minIdx > maxIdx) {
            int lenght = (nums.size() - maxIdx);
            sides = min(sides, lenght);
        }

        if (minIdx < maxIdx) {
            int lenght = maxIdx + 1;
            sides = min(sides, lenght);
        }

        if (maxIdx > minIdx) {
            int lenght = nums.size() - minIdx;
            sides = min(sides, lenght);
        }

        if (maxIdx < minIdx) {
            int lenght = minIdx + 1;
            sides = min(sides, lenght);
        }

        return min(total, sides);
    }
};