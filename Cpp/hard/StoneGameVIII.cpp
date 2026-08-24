#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int scoreA = 0, scoreB = 0;
        
        vector<int> ps(stones.size());
        
        ps[0] = stones[0];
        for(int i = 1; i < stones.size(); i++) {
            ps[i] = ps[i-1] + stones[i];
        }

        int melhor = ps[stones.size() - 1];

        for(int i = stones.size() - 2; i >= 1; i--) {
            melhor = max(melhor, ps[i] - melhor);
        }

        return melhor;
    }
};