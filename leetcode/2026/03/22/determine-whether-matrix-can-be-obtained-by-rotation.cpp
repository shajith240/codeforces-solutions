/*
 * Problem: Determine Whether Matrix Can Be Obtained By Rotation
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 * Language: cpp
 * Topics: Array, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two n x n binary matrices mat and target , return true if it is possible to make mat equal to target by rotating mat in 90-degree increments , or false otherwise.
 * Example 1:
 * Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
 * Output: true
 * Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
 * Example 2:
 * Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
 * Output: false
 * Explanation: It is impossible to make mat equal to target by rotating mat.
 * Example 3:
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
 * Output: true
 * Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 * Constraints:
 * • n == mat.length == target.length
 * • n == mat[i].length == target[i].length
 * • 1 <= n <= 10
 * • mat[i][j] and target[i][j] are either 0 or 1 .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: What is the maximum number of rotations you have to check?
 * Hint 2: Is there a formula you can use to rotate a matrix 90 degrees?
 * 
 */

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i = 0 ; i < 4 ; i++){
            
            if(mat == target){
                return true;
            }

            //rotate the matrix 
            int n = mat.size();
            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1 ; j < n ; j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }

            for(int i = 0 ; i < n ; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};