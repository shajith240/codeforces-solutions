/*
 * Problem: Maximum Non Negative Product in a Matrix
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
 * Language: cpp
 * Topics: Array, Dynamic Programming, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a m x n matrix grid . Initially, you are located at the top-left corner (0, 0) , and in each step, you can only move right or down in the matrix.
 * Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1) , find the path with the maximum non-negative product . The product of a path is the product of all integers in the grid cells visited along the path.
 * Return the maximum non-negative product modulo 10 9 + 7 . If the maximum product is negative , return -1 .
 * Notice that the modulo is performed after getting the maximum product.
 * Example 1:
 * Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
 * Output: -1
 * Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
 * Example 2:
 * Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
 * Output: 8
 * Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
 * Example 3:
 * Input: grid = [[1,3],[0,-4]]
 * Output: 0
 * Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
 * Constraints:
 * • m == grid.length
 * • n == grid[i].length
 * • 1 <= m, n <= 15
 * • -4 <= grid[i][j] <= 4
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use Dynamic programming. Keep the highest value and lowest value you can achieve up to a point.
 * 
 */

class Solution {
public:
    pair<long long, long long>
    solve(vector<vector<int>>& grid, int i, int j, int m, int n,
          vector<vector<pair<long long, long long>>>& t) {

        
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        // Return cached result (we use a sentinel value like a huge minimum to
        // check if visited)
        if (t[i][j].first != LLONG_MIN) {
            return t[i][j];
        }

        long long min_val = LLONG_MAX;
        long long max_val = LLONG_MIN;

        // Try moving DOWN
        if (i + 1 < m) {
            auto down = solve(grid, i + 1, j, m, n, t);
            // Multiply grid value by both min and max of the downward path
            min_val = min(
                {min_val, down.first * grid[i][j], down.second * grid[i][j]});
            max_val = max(
                {max_val, down.first * grid[i][j], down.second * grid[i][j]});
        }

        // Try moving RIGHT
        if (j + 1 < n) {
            auto right = solve(grid, i, j + 1, m, n, t);
            // Multiply grid value by both min and max of the rightward path
            min_val = min(
                {min_val, right.first * grid[i][j], right.second * grid[i][j]});
            max_val = max(
                {max_val, right.first * grid[i][j], right.second * grid[i][j]});
        }

        // Cache and return both the min and max possible products from this
        // cell
        return t[i][j] = {min_val, max_val};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long mod = 1e7 + 7;

     vector<vector<pair<long long, long long>>> t(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        pair<long long, long long> ans = solve(grid, 0, 0, m, n, t);

        long long maxproduct = ans.second;

        if (maxproduct >= 0) {
            return maxproduct % 1000000007;
        }
        return -1;
    }
};