/*
 * Problem: Number of Islands
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-islands/
 * Language: cpp
 * Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an m x n 2D binary grid grid which represents a map of &#39;1&#39; s (land) and &#39;0&#39; s (water), return the number of islands .
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 * Example 1:
 * Input: grid = [
 * [&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;0&quot;],
 * [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;],
 * [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
 * [&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;]
 * ]
 * Output: 1
 * Example 2:
 * Input: grid = [
 * [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
 * [&quot;1&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;],
 * [&quot;0&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;],
 * [&quot;0&quot;,&quot;0&quot;,&quot;0&quot;,&quot;1&quot;,&quot;1&quot;]
 * ]
 * Output: 3
 * Constraints:
 * • m == grid.length
 * • n == grid[i].length
 * • 1 <= m, n <= 300
 * • grid[i][j] is &#39;0&#39; or &#39;1&#39; .
 * 
 */

class Solution {
public:

    int m ;
    int n ;

    void dfs(vector<vector<char>>& grid , int i , int j){

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){
            return;
        }
        

        grid[i][j] = '$';

        dfs(grid,i + 1, j);
        dfs(grid,i - 1 , j);
        dfs(grid,i,j + 1);
        dfs(grid,i,j - 1);
    }


    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        int island = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    island += 1;
                }
            }
        }

        return island;
    }
};