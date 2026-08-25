/* You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, x = 0;

        string nS = to_string(n);
        string newN = "";

        for (long long i = 0; i < nS.size(); i++)
        {
            if (nS[i] != '0') {
                newN.push_back(nS[i]);
                sum += nS[i] - '0';
            }
        }

        if (newN.size() > 0) {
            x = stoi(newN);
        }

        return sum * x;

    }
};