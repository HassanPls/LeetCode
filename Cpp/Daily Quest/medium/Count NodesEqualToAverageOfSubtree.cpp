#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int count = 0;

    pair<int, int> dfs(TreeNode* node) {

        if (node == nullptr) return {0, 0};

        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);

        int sum = node->val + left.first + right.first;
        int num_nodes = 1 + left.second + right.second;

        if (sum/num_nodes == node->val) count++;

        return {sum, num_nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};