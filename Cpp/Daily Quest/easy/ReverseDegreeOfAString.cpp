#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        long long totalSum = 0;
        for(int i = 0; i < s.size(); i++) {
            long long reversedIndex = ((s[i] - 'z') * -1) + 1;
            long long product = reversedIndex * (i + 1);
            totalSum += product;
        }
        return totalSum;
    }
};