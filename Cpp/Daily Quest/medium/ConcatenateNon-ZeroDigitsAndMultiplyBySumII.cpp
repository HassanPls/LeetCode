/* You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        long long MOD = 1000000007;

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_x(m + 1, 0);
        vector<int> cont_non_zero(m + 1, 0);

        for (int i = 0; i < m; i++) {
            int num = s[i] - '0';
            
            if (num != 0) {
                pref_sum[i + 1] = pref_sum[i] + num;
                pref_x[i + 1] = (pref_x[i] * 10 + num) % MOD;
                cont_non_zero[i + 1] = cont_non_zero[i] + 1;
            } else {
                pref_sum[i + 1] = pref_sum[i];
                pref_x[i + 1] = pref_x[i]; 
                cont_non_zero[i + 1] = cont_non_zero[i];
            }
        }
        
        vector<int> answer(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            int digitos_no_intervalo = cont_non_zero[r + 1] - cont_non_zero[l];
            long long current_x = (pref_x[r + 1] - (pref_x[l] * pow10[digitos_no_intervalo]) % MOD + MOD) % MOD;

            answer[i] = (current_x * (current_sum % MOD)) % MOD;
        }

        return answer;
    }
};