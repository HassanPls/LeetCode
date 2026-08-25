/* You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nao_zeros = false;
        int total_xor = 0;

        for(auto x: nums) {
            total_xor ^= x;
            if (x != 0) {
                nao_zeros = true;
            }
        }

        if (!nao_zeros) {
            return 0;
        }

        if (total_xor != 0) {
            return nums.size();
        }

        return nums.size() - 1;
    }
};