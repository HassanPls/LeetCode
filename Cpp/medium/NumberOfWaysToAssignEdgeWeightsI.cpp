#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long fast_pow(long long base, long long expoente, long long modulo)
    {
        long long resultado = 1;
        base %= modulo;
        while (expoente > 0)
        {
            if (expoente % 2 == 1)
            {
                resultado = (resultado * base) % modulo;
            }
            base = (base * base) % modulo;
            expoente /= 2;
        }
        return resultado;
    }

    void dfs(int no_atual, int no_pai, int edgesAccumulated, const unordered_map<int, vector<int>> &grafo, int &max_edges)
    {
        max_edges = std::max(max_edges, edgesAccumulated);

        for (auto vizinho : grafo.at(no_atual))
        {
            if (vizinho != no_pai)
            {
                dfs(vizinho, no_atual, edgesAccumulated + 1, grafo, max_edges);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> grafo = {};

        for (auto u : edges)
        {
            grafo[u[0]].push_back(u[1]);
            grafo[u[1]].push_back(u[0]);
        }

        int max_edges = 0;

        dfs(1, 0, 0, grafo, max_edges);

        return fast_pow(2, max_edges - 1, 1e9 + 7);
    }
};