#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {

        long long result = 0, sup = 1000;

        while (n >= sup)
        {
            result += n - sup + 1;
            sup *= 1000;
        }
        
        return result;
    }
};