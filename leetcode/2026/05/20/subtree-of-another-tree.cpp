/*
 * Problem: Subtree of Another Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/subtree-of-another-tree/
 * Language: cpp
 * Topics: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the roots of two binary trees root and subRoot , return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
 * A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node&#39;s descendants. The tree tree could also be considered as a subtree of itself.
 * Example 1:
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 * Example 2:
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 * Constraints:
 * • The number of nodes in the root tree is in the range [1, 2000] .
 * • The number of nodes in the subRoot tree is in the range [1, 1000] .
 * • -10 4 <= root.val <= 10 4
 * • -10 4 <= subRoot.val <= 10 4
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Which approach is better here- recursive or iterative?
 * Hint 2: If recursive approach is better, can you write recursive function with its parameters?
 * Hint 3: Two trees s and t are said to be identical if their root values are same and their left and right subtrees are identical. Can you write this in form of recursive formulae?
 * Hint 4: Recursive formulae can be:
 * isIdentical(s,t)= s.val==t.val AND isIdentical(s.left,t.left) AND isIdentical(s.right,t.right)
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

    bool isSametree(TreeNode* p,TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }

        if(p == NULL || q == NULL){
            return false;
        }


        if(p->val != q->val){
            return false;
        }

        return isSametree(p->left,q->left) && isSametree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         
         if(root == NULL){
            return false;
         }

         if(isSametree(root,subRoot)){
            return true;
         }

         return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};