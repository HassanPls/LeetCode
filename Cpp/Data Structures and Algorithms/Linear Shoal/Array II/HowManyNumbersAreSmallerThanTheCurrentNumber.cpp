#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> maiores(101, 0);
        vector<int> ans;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        maiores[sortedNums[0]] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int index = i;

            while (index > 0 && sortedNums[index - 1] == sortedNums[index])
            {
                index--;
            }
            
            maiores[sortedNums[i]] = index;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(maiores[nums[i]]);
        }
        
        return ans;
    }
};