#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;

        for(int num: nums1) {
            if (num < mn) {
                mn = num;
            }
            if (num & 1) {
                hasOdd = true;
            }
        }

        if (mn & 1) return true;
        return !hasOdd;
    }
};