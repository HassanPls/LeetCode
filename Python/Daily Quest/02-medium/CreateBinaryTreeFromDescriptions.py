""" You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid. """

# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: list[list[int]]) -> Optional[TreeNode]:
        
        nodes = {}
        children = set()

        ans = [0] * (2 * len(descriptions)) 

        for parent, child, isleft in descriptions:
            if parent not in nodes:
                nodes[parent] = TreeNode(parent)

            if child not in nodes:
                nodes[child] = TreeNode(child)

            children.add(child)

            if isleft == 1:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]

        for parent in nodes:
            if parent not in children:
                return nodes[parent]

        return ans