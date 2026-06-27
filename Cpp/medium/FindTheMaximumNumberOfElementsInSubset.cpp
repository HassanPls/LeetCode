/* You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check_piramid(long long x, unordered_map<long long, int> &est) {
        if (est[x] >= 2 && est.count(x*x) && est[x*x] > 0) {
            return 2 + check_piramid(x * x, est);
        } else if (est[x] >= 1) {
            return 1;
        } else {
            return -1;
        }
    }

    int maximumLength(vector<int>& nums) {
        int maior_piramide = 1;
        unordered_map<long long, int> est;

        for (int num: nums)
        {
            est[num]++;
        }
        
        if(est[1] > 0) {
            int qnt_uns = est[1];
            if (qnt_uns%2==0) qnt_uns--;
            maior_piramide = max(maior_piramide, qnt_uns);
        }

        for(auto p: est) {
            long long firstPair = p.first;

            if (firstPair == 1) continue;

            int tamanho = check_piramid(firstPair, est);

            maior_piramide = max(maior_piramide, tamanho);
        }

        return maior_piramide;
    }
};