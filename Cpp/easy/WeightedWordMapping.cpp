#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int> totalWeights;

        for (size_t i = 0; i < words.size(); i++)
        {
            int weight = 0;
            for (size_t j = 0; j < words[i].length(); j++)
            {
                weight += weights[words[i][j] - 'a'];
            }
            totalWeights.push_back(weight % 26);
        }
        
        string answer = "";

        for (size_t i = 0; i < totalWeights.size(); i++)
        {
            char caracter = 'z' - totalWeights[i];
            answer += caracter;
        }

        return answer;
    }
};