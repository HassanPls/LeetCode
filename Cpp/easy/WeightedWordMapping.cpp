/* You are given an array of strings words, where each string represents a word containing lowercase English letters.

You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

The weight of a word is defined as the sum of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

Return a string formed by concatenating the mapped characters for all words in order. */

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