/*
 * Problem: Minimum Path Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-path-sum/
 * Language: cpp
 * Topics: Array, Dynamic Programming, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * Example 1:
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
 * Example 2:
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * Constraints:
 * • m == grid.length
 * • n == grid[i].length
 * • 1 <= m, n <= 200
 * • 0 <= grid[i][j] <= 200
 * 
 */

class Solution {
public:

    int solve(vector<vector<int>>& grid, int i , int j , int m , int n,vector<vector<int>>& t){
        
        if(i == m - 1 && j == n - 1){
            return grid[i][j];
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }

        if(i == m - 1){
            return t[i][j] = grid[i][j] + solve(grid,i,j+1,m,n,t);
        }
        else if(j == n - 1){
            return t[i][j] = grid[i][j] + solve(grid,i+1,j,m,n,t);
        }

        else{
            return t[i][j] = grid[i][j] + min(solve(grid,i+1,j,m,n,t) , solve(grid,i,j+1,m,n,t));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(grid,0,0,m,n,t);
    }
};