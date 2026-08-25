/* You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.

Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component_id(n);
        int id = 0;
        component_id[0] = 0;

        for (size_t i = 1; i < n; i++)
        {
            if (abs(nums[i] - nums[i-1]) > maxDiff) id++;
            component_id[i] = id;
        }
        
        vector<bool> answer(queries.size());

        for (size_t i = 0; i < queries.size(); i++)
        {
            answer[i] = (component_id[queries[i][0]] == component_id[queries[i][1]]);
        }

        return answer;
        
    }
};