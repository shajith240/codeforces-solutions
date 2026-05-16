/*
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Language: cpp
 * Topics: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree .
 * Example 1:
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * Constraints:
 * • 1 <= preorder.length <= 3000
 * • inorder.length == preorder.length
 * • -3000 <= preorder[i], inorder[i] <= 3000
 * • preorder and inorder consist of unique values.
 * • Each value of inorder also appears in preorder .
 * • preorder is guaranteed to be the preorder traversal of the tree.
 * • inorder is guaranteed to be the inorder traversal of the tree.
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
    
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int start,int end,int &idx){
        
        if(start > end){
            return NULL;
        }

        int rootVal = preorder[idx];

        int i = start;
        for(; i <= end ; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }
        
        idx++;
        TreeNode * root = new TreeNode(rootVal);
        root->left = solve(preorder,inorder,start,i - 1,idx);
        root->right = solve(preorder,inorder,i+1,end,idx);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        int start = 0;
        int end = n - 1;
        return solve(preorder,inorder,start,end,idx);
    }
};