#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> hasNum(nums.size() + 1);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) hasNum[nums[i]] = true;
        for (int i = 1; i < nums.size() + 1; i++)
        {
            if (!hasNum[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};