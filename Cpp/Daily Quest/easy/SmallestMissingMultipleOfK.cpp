#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> numeros(10001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            numeros[nums[i]]++;
        }
        
        for (int i = 1; i < numeros.size(); i++)
        {
            if (numeros[i * k] == 0) return i * k;
        }

        return 0;
    }
};