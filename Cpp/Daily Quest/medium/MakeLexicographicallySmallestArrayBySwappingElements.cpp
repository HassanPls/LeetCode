#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> numsAndIndice(n);
        for (int i = 0; i < n; i++) numsAndIndice[i] = {nums[i], i};
        sort(numsAndIndice.begin(), numsAndIndice.end());

        int i = 0;
        vector<int> result(n);
        while (i < n)
        {
            int j = i;

            vector<int> group_values;
            vector<int> group_indices;

            group_values.push_back(numsAndIndice[j].first);
            group_indices.push_back(numsAndIndice[j].second);

            while (j + 1 < n && (numsAndIndice[j + 1].first - numsAndIndice[j].first) <= limit)
            {
                j++;
                group_values.push_back(numsAndIndice[j].first);
                group_indices.push_back(numsAndIndice[j].second);
            }

            sort(group_indices.begin(), group_indices.end());

            for (int k = 0; k < group_indices.size(); k++)
            {
                result[group_indices[k]] = group_values[k];
            }
            
            i = j + 1;
        }
        
        return result;
    }
};