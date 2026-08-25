/* It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost =  *max_element(costs.begin(), costs.end());
        vector<int> countingSortCosts(maxCost + 1,0);
        
        for(int i = 0; i < costs.size(); i++) {
            countingSortCosts[costs[i]]++;
        }
        
        int total= 0;
        for(int i = 0; i < maxCost + 1; i++) {
            for(int j = 0; j < countingSortCosts[i]; j++) {
                costs[total] = i;
                total++;
            }
        }
        
        int maxIceCream = 0;
        for(int i = 0; i < costs.size(); i++) {
            if (coins < costs[i]) break;
            
            maxIceCream++;
            coins -= costs[i];
        }
        
        return maxIceCream;
    }
};