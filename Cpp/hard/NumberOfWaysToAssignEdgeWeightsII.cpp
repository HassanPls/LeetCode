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
    int max_log;
    vector<int> profundidade;
    vector<vector<int>> ancestral;

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

    void dfs_precomputacao(int no, int pai, int p, const vector<vector<int>>& grafo) {
        profundidade[no] = p;
        ancestral[no][0] = pai;

        for (int vizinho : grafo[no]) {
            if (vizinho != pai) {
                dfs_precomputacao(vizinho, no, p + 1, grafo);
            }
        }
    }

    int getLca(int u, int v) {
        if (profundidade[u] < profundidade[v]) swap(u, v);

        for (int i = max_log - 1; i >= 0; i--) {
            if (profundidade[u] - (1 << i) >= profundidade[v]) {
                u = ancestral[u][i];
            }
        }

        if (u == v) return u;

        for (int i = max_log - 1; i >= 0; i--) {
            if (ancestral[u][i] != ancestral[v][i]) {
                u = ancestral[u][i];
                v = ancestral[v][i];
            }
        }
        return ancestral[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        int n = edges.size() + 1;
        max_log = log2(n) + 1;
        vector<vector<int>> grafo(n + 1);
        vector<int> answer;

        for (auto u : edges)
        {
            grafo[u[0]].push_back(u[1]);
            grafo[u[1]].push_back(u[0]);
        }

        profundidade.assign(n + 1, 0);
        ancestral.assign(n + 1, vector<int>(max_log, 0));

        dfs_precomputacao(1, 0, 0, grafo);

        for (int i = 1; i < max_log; i++) {
            for (int j = 1; j <= n; j++) {
                if (ancestral[j][i - 1] != 0) {
                    ancestral[j][i] = ancestral[ancestral[j][i - 1]][i - 1];
                }
            }
        }

        for(auto& q: queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLca(u, v);
            int total_edges = profundidade[u] + profundidade[v] - 2 * profundidade[lca];
            answer.push_back(fast_pow(2, total_edges - 1, 1e9 + 7));
        }

        return answer;
    }
};