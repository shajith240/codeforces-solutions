/*
 * Problem: Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * Language: cpp
 * Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a binary tree root , a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
 * Return the number of good nodes in the binary tree.
 * Example 1:
 * Input: root = [3,1,4,3,null,1,5]
 * Output: 4
 * Explanation: Nodes in blue are good .
 * Root Node (3) is always a good node.
 * Node 4 -> (3,4) is the maximum value in the path starting from the root.
 * Node 5 -> (3,4,5) is the maximum value in the path
 * Node 3 -> (3,1,3) is the maximum value in the path.
 * Example 2:
 * Input: root = [3,3,null,4,2]
 * Output: 3
 * Explanation: Node 2 -> (3, 3, 2) is not good, because &quot;3&quot; is higher than it.
 * Example 3:
 * Input: root = [1]
 * Output: 1
 * Explanation: Root is considered as good .
 * Constraints:
 * • The number of nodes in the binary tree is in the range [1, 10^5] .
 * • Each node&#39;s value is between [-10^4, 10^4] .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use DFS (Depth First Search) to traverse the tree, and constantly keep track of the current path maximum.
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int max_so_far){
      if(root == NULL){
        return 0;
      }
      
      int count = 0;
      
      if(root->val >= max_so_far){
        count = 1;
      }

      max_so_far = max(max_so_far,root->val);

      return count + dfs(root->left,max_so_far) + dfs(root->right,max_so_far);

    }

    int goodNodes(TreeNode* root) {
        int max_so_far = INT_MIN;
        return dfs(root,max_so_far);
    }
};