#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> elementosOrdenados(arr.begin(), arr.end());

        unordered_map<int, int> mapeamentoRank;
        int rankAtual = 1;

        for (int num : elementosOrdenados)
        {
            mapeamentoRank[num] = rankAtual;
            rankAtual++;
        }
        
        for (size_t i = 0; i < arr.size(); i++)
        {
            arr[i] = mapeamentoRank[arr[i]];
        }
        
        return arr;
    }
};