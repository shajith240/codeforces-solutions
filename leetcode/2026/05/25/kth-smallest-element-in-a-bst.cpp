/*
 * Problem: Kth Smallest Element in a BST
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Language: cpp
 * Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the root of a binary search tree, and an integer k , return the k th smallest value ( 1-indexed ) of all the values of the nodes in the tree .
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 * Constraints:
 * • The number of nodes in the tree is n .
 * • 1 <= k <= n <= 10 4
 * • 0 <= Node.val <= 10 4
 * Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Try to utilize the property of a BST.
 * Hint 2: Try in-order traversal. (Credits to @chan13)
 * Hint 3: What if you could modify the BST node's structure?
 * Hint 4: The optimal runtime complexity is O(height of BST).
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
    
    int count = 0;
    int ans  = 0;
    void dfs(TreeNode* Node,int k){
        
        if(Node == NULL){
            return ;
        }
        dfs(Node->left,k);
        count++;
        if(count == k){
            ans = Node->val;
        }
        dfs(Node->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};