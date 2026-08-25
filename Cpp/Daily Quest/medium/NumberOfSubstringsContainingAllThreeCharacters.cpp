/* Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ultimas_posicoes(3, -1);
        int total = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            ultimas_posicoes[s[i] - 'a'] = i;

            if (ultimas_posicoes[0] != -1 && ultimas_posicoes[1] != -1 && ultimas_posicoes[2] != -1) {
                int menor_indice = min({ultimas_posicoes[0], ultimas_posicoes[1], ultimas_posicoes[2]});

                total += menor_indice + 1;
            }
        }
        
        return total;
    }
};