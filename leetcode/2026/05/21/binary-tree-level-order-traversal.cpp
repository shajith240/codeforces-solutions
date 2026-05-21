/*
 * Problem: Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Language: cpp
 * Topics: Tree, Breadth-First Search, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the root of a binary tree, return the level order traversal of its nodes&#39; values . (i.e., from left to right, level by level).
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 * Example 3:
 * Input: root = []
 * Output: []
 * Constraints:
 * • The number of nodes in the tree is in the range [0, 2000] .
 * • -1000 <= Node.val <= 1000
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use a queue to perform BFS.
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* Node = q.front();

                q.pop();
                if (Node->left != NULL)
                    q.push(Node->left);
                if (Node->right != NULL)
                    q.push(Node->right);
                level.push_back(Node->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};