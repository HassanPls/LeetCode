""" There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.

Since the answer may be large, return it modulo 109 + 7.

Note: Ignore all edges not in the path from node 1 to x. """

class Solution:
    def assignEdgeWeights(self, edges: list[list[int]]) -> int:
        grafo = {}

        for u, v in edges:
            if u not in grafo:
                grafo[u] = []

            grafo[u].append(v)

            if v not in grafo:
                grafo[v] = []

            grafo[v].append(u)

        max_arestas = 0

        def recursive(no_atual, no_pai, edgesAccumulated):
            nonlocal max_arestas
            max_arestas = max(max_arestas, edgesAccumulated)

            for vizinho in grafo[no_atual]:
                if (vizinho != no_pai):
                    recursive(vizinho, no_atual, edgesAccumulated + 1)

        recursive(1, 0, 0)
        
        return pow(2, max_arestas-1, 10**9 + 7)
    