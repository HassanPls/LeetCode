#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> feq(26, 0);
        for(auto c: s) {
            feq[c - 'a']++;
        }

        string bestAns = "";

        for (int i = 0; i < n; i++)
        {
            for (char c = target[i] + 1; c <= 'z'; c++)
            {
                if (feq[c - 'a'] > 0) {
                    feq[c - 'a']--;

                    string cand = target.substr(0, i);
                    cand += c;

                    for (int j = 0; j < 26; j++)
                    {
                        cand.append(feq[j], 'a' + j);
                    }
                    
                    if (bestAns == "" || cand < bestAns) {
                        bestAns = cand;
                    }

                    feq[c - 'a']++;
                }
            }

            if (feq[target[i] - 'a'] > 0) {
                feq[target[i] - 'a']--;
            } else {
                break;
            }
            
        }

        return bestAns;
        
    }
};