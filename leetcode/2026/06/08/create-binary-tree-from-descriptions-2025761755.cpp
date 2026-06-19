/*
 * Problem: Create Binary Tree From Descriptions
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/
 * Language: cpp
 * Topics: Array, Hash Table, Tree, Binary Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a 2D integer array descriptions where descriptions[i] = [parent i , child i , isLeft i ] indicates that parent i is the parent of child i in a binary tree of unique values. Furthermore,
 * • If isLeft i == 1 , then child i is the left child of parent i .
 * • If isLeft i == 0 , then child i is the right child of parent i .
 * Construct the binary tree described by descriptions and return its root .
 * The test cases will be generated such that the binary tree is valid .
 * Example 1:
 * Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
 * Output: [50,20,80,15,17,19]
 * Explanation: The root node is the node with value 50 since it has no parent.
 * The resulting binary tree is shown in the diagram.
 * Example 2:
 * Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
 * Output: [1,2,null,null,3,4]
 * Explanation: The root node is the node with value 1 since it has no parent.
 * The resulting binary tree is shown in the diagram.
 * Constraints:
 * • 1 <= descriptions.length <= 10 4
 * • descriptions[i].length == 3
 * • 1 <= parent i , child i <= 10 5
 * • 0 <= isLeft i <= 1
 * • The binary tree described by descriptions is valid.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Could you represent and store the descriptions more efficiently?
 * Hint 2: Could you find the root node?
 * Hint 3: The node that is not a child in any of the descriptions is the root node.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; //they can never be root of the tree


        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }


        //Find the root
        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; //we will never reach here
    }
};