#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> prefix(n, INF);
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;

        int current_sum = 0;
        int ans = INF;
        int current_min = INF;

        for (int i = 0; i < n; i++)
        {
            current_sum += arr[i];

            int needed = current_sum - target;
            if (prefix_map.count(needed)) {
                int start_i = prefix_map[needed];
                int length = i - start_i;

                if (start_i >= 0 && prefix[start_i] != INF) {
                    ans = min(ans, prefix[start_i] + length);
                }

                current_min = min(current_min, length);
            }

            prefix[i] = current_min;
            prefix_map[current_sum] = i;
        }
        
        return (ans >= INF) ? -1 : ans;
    }
};