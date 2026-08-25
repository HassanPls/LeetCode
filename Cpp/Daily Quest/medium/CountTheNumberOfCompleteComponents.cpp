#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int no, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& bloco) {
        visited[no] = true;
        bloco.push_back(no);

        for (int vizinho : adj[no])
        {
            if (!visited[vizinho]) {
                dfs(vizinho, adj, visited, bloco);
            }
        }
        
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int componentes_completos = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (!visited[i]) {
                vector<int> bloco;

                dfs(i, adj, visited, bloco);

                int k = bloco.size();
                int total_conexoes = 0;

                for (int no : bloco)
                {
                    total_conexoes += adj[no].size();
                }
                
                if (total_conexoes == k * (k-1)) {
                    componentes_completos++;
                }
            }
        }
        
        return componentes_completos;

    }
};