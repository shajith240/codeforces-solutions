/*
 * Problem: Surrounded Regions
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/surrounded-regions/
 * Language: cpp
 * Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an m x n matrix board containing letters &#39;X&#39; and &#39;O&#39; , capture regions that are surrounded :
 * • Connect : A cell is connected to adjacent cells horizontally or vertically.
 * • Region : To form a region connect every &#39;O&#39; cell.
 * • Surround : A region is surrounded if none of the &#39;O&#39; cells in that region are on the edge of the board. Such regions are completely enclosed by &#39;X&#39; cells.
 * To capture a surrounded region , replace all &#39;O&#39; s with &#39;X&#39; s in-place within the original board. You do not need to return anything.
 * Example 1:
 * Input: board = [[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;O&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;O&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;X&quot;,&quot;X&quot;]]
 * Output: [[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;X&quot;,&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;O&quot;,&quot;X&quot;,&quot;X&quot;]]
 * Explanation:
 * In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
 * Example 2:
 * Input: board = [[&quot;X&quot;]]
 * Output: [[&quot;X&quot;]]
 * Constraints:
 * • m == board.length
 * • n == board[i].length
 * • 1 <= m, n <= 200
 * • board[i][j] is &#39;X&#39; or &#39;O&#39; .
 * 
 */

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<char>>& board, int i, int j,
             vector<vector<bool>>& Visited) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }

        if (board[i][j] != 'O' || Visited[i][j]) {
            return;
        }

        Visited[i][j] = true;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(board, i_, j_, Visited);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> Visited(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) {
            DFS(board, 0, j, Visited);
            DFS(board, m - 1, j, Visited);
        }

        for (int i = 0; i < m; i++) {
            DFS(board, i, 0, Visited);
            DFS(board, i, n - 1, Visited);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !Visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
