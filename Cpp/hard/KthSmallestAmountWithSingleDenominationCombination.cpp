#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mmc(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long contaMultiplos(long long V, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm_atual = 1;
            int bits_ativos = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits_ativos++;
                    lcm_atual = mmc(lcm_atual, coins[i]);
                    if (lcm_atual > V) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bits_ativos % 2 != 0) {
                total += V / lcm_atual;
            } else {
                total -= V / lcm_atual;
            }
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * (long long)k; 
        
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (contaMultiplos(mid, coins) >= k) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};