/*
 * Problem: Binary Tree Right Side View
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
 * Language: cpp
 * Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom .
 * Example 1:
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 * Explanation:
 * Example 2:
 * Input: root = [1,2,3,4,null,null,null,5]
 * Output: [1,3,4,5]
 * Explanation:
 * Example 3:
 * Input: root = [1,null,3]
 * Output: [1,3]
 * Example 4:
 * Input: root = []
 * Output: []
 * Constraints:
 * • The number of nodes in the tree is in the range [0, 100] .
 * • -100 <= Node.val <= 100
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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        vector<int> ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
           
           int n = que.size();

           TreeNode* node = NULL;

           while(n--){
             node = que.front();

             que.pop();
             if(node->left != NULL){
                que.push(node->left);
             }
             if(node->right != NULL){
                que.push(node->right);
             }
           }

           ans.push_back(node->val);
        } 
        return ans;
    }
};