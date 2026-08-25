#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++)
        {
            ans[i*2] = nums[i];
            ans[i*2 + 1] = nums[i + n];
        }
        
        return ans;
    }
};

/* 100%:

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp;
        for(int i = 0; i < n; ++i){
           temp.push_back(nums[i]);
           temp.push_back(nums[i+n]); 
        }
        return temp;
    }
}; */