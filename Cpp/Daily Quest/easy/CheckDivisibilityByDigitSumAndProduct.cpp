#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int initNum = n;
        int totalSum = 0;
        int totalProduct = 1;

        while (initNum > 0)
        {
            int num = initNum%10;
            initNum -= num;
            initNum = initNum/10;
            
            totalSum += num;
            totalProduct *= num;
        }
        
        int total = totalSum + totalProduct;

        return (n % total == 0);
    }
};