#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> feq(1e5, 0);
        vector<int> ans(2);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) feq[nums[i]]++;
        
        for(int i = 1; i <= nums.size(); i++) {
            if (feq[i] == 2) {
                ans[0] = i;
            }

            if (feq[i] == 0) {
                ans[1] = i;
            }
        }
        
        return ans;
    }
};