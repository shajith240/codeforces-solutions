/*
 * Problem: Maximum Path Intersection Sum in a Grid
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/
 * Language: cpp
 * Topics: 
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an m x n integer matrix grid .
 * Two players move across the grid:
 * • Player 1 starts at the top-left cell (0, 0) and can move only right or down. Their destination is the bottom-right cell (m - 1, n - 1) .
 * • Player 2 starts at the bottom-left cell (m - 1, 0) and can move only right or up. Their destination is the top-right cell (0, n - 1) .
 * Each player must choose a valid path from their respective starting cell to their destination.
 * A cell is called shared if it belongs to both chosen paths.
 * Return an integer denoting the maximum possible sum of values of all shared cells.
 * Example 1:
 * ​​​​​​​​​​​​​​​​​​​​​
 * Input: grid = [[1,2,0,-3],[1,-2,1,0],[-4,2,-1,3],[3,-3,3,-2],[-1,-5,0,1]]
 * Output: 4
 * Explanation:
 * The diagram shows one optimal choice of paths.
 * • Player 1 follows the red/purple path from the top-left cell to the bottom-right cell:
 * • (0, 0) &rarr; (1, 0) &rarr; (2, 0) &rarr; (2, 1) &rarr; (2, 2) &rarr; (2, 3) &rarr; (3, 3) &rarr; (4, 3)
 * • Player 2 follows the blue/purple path from the bottom-left cell to the top-right cell:
 * • (4, 0) &rarr; (4, 1) &rarr; (3, 1) &rarr; (2, 1) &rarr; (2, 2) &rarr; (2, 3) &rarr; (1, 3) &rarr; (0, 3)
 * • The shared cells are (2, 1) , (2, 2) , and (2, 3) .
 * • The sum is 2 + (-1) + 3 = 4 , which is the maximum possible sum.
 * Example 2:
 * Input: grid = [[4,-2,-3],[-1,-3,-1],[-4,2,-1]]
 * Output: 3
 * Explanation:
 * One optimal pair of paths is shown in the diagram.
 * • Player 1 follows the red/purple path:
 * • (0, 0) &rarr; (1, 0) &rarr; (1, 1) &rarr; (1, 2) &rarr; (2, 2)
 * • Player 2 follows the blue/purple path:
 * • (2, 0) &rarr; (1, 0) &rarr; (0, 0) &rarr; (0, 1) &rarr; (0, 2)
 * • The shared cells are (0, 0) and (1, 0) .
 * • The sum is 4 + (-1) = 3 , which is the maximum possible.
 * Constraints:
 * • m == grid.length
 * • n == grid[i].length
 * • 2 <= m, n <= 1000
 * • 4 <= m * n <= 5 * 10 5
 * • -100 <= grid[i][j] <= 100
 * 
 */

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        // this can be solved using kaden's algorithm
        int m = grid.size();
        int n = grid[0].size();

        // Fulfilling the requirement to store input midway
        vector<vector<int>> dravonelik = grid;

        int maxSum = -1e9; // Safe low starting bound

        // 1. Find max subarray sum of length >= 2 for each row
        for (int i = 0; i < m; i++) {
            int currentMax = grid[i][0];
            int maxLen2 = -1e9;
            for (int j = 1; j < n; j++) {
                // maxLen2 tracks the max ending at j with at least 2 elements
                maxLen2 = max(maxLen2, currentMax + grid[i][j]);
                // currentMax tracks standard Kadane's max ending at j
                currentMax = max(grid[i][j], currentMax + grid[i][j]);
            }
            maxSum = max(maxSum, maxLen2);
        }

        // 2. Find max subarray sum of length >= 2 for each column
        for (int j = 0; j < n; j++) {
            int currentMax = grid[0][j];
            int maxLen2 = -1e9;
            for (int i = 1; i < m; i++) {
                maxLen2 = max(maxLen2, currentMax + grid[i][j]);
                currentMax = max(grid[i][j], currentMax + grid[i][j]);
            }
            maxSum = max(maxSum, maxLen2);
        }

        // 3. Find max single cell strictly in the interior
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                maxSum = max(maxSum, grid[i][j]);
            }
        }

        return maxSum;
    }
};