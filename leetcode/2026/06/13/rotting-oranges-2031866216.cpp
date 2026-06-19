/*
 * Problem: Rotting Oranges
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotting-oranges/
 * Language: cpp
 * Topics: Array, Breadth-First Search, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an m x n grid where each cell can have one of three values:
 * • 0 representing an empty cell,
 * • 1 representing a fresh orange, or
 * • 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange . If this is impossible, return -1 .
 * Example 1:
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * Example 2:
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 * Example 3:
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 * Constraints:
 * • m == grid.length
 * • n == grid[i].length
 * • 1 <= m, n <= 10
 * • grid[i][j] is 0 , 1 , or 2 .
 * 
 */

class Solution {
public:
    typedef pair<int, int> P;

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> que;
        int freshcount = 0;
        int minutes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshcount++;
                } else if (grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }

        if (freshcount == 0) {
            return 0;
        }

        int miniutes = 0;

        while (!que.empty()) {
            int N = que.size();
            
            while (N--) {

                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;

                for (vector<int> &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2;
                        que.push({new_i, new_j});
                        freshcount--;
                    }
                }
               
            }
             minutes++;
        }

        return freshcount == 0 ? minutes - 1 : -1;
    }
};