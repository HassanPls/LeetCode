/* There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

Return an array answer, where answer[i] is the number of valid assignments for queries[i].

Since the answer may be large, apply modulo 109 + 7 to each answer[i].

Note: For each query, disregard all edges not in the path between node ui and vi. */

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

    int dfs(int no_atual, int no_pai, int edgesAccumulated, const unordered_map<int, vector<int>> &grafo, int &max_edges, int end)
    {
        if (no_atual == end) {
            return 0;
        }

        max_edges = std::max(max_edges, edgesAccumulated);

        for (auto vizinho : grafo.at(no_atual))
        {
            if (vizinho != no_pai)
            {
                int distance = dfs(vizinho, no_atual, edgesAccumulated + 1, grafo, max_edges, end);
                if (distance != -1) {
                    return distance + 1;
                }
            }
        }

        return -1;
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {

        unordered_map<int, vector<int>> grafo = {};
        vector<int> answer;

        for (auto u : edges)
        {
            grafo[u[0]].push_back(u[1]);
            grafo[u[1]].push_back(u[0]);
        }

        for (size_t i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == queries[i][1]) {
                answer.push_back(0);
                continue;
            }

            int max_edges = dfs(queries[i][0], 0, 0, grafo, max_edges, queries[i][1]);

            int totalAssignments = fast_pow(2, max_edges - 1, 1e9 + 7);
            answer.push_back(totalAssignments);
        }

        return answer;
    }
};