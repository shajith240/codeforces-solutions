/*
 * Problem: Valid Sudoku
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/valid-sudoku/
 * Language: cpp
 * Topics: Array, Hash Table, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules :
 * • Each row must contain the digits 1-9 without repetition.
 * • Each column must contain the digits 1-9 without repetition.
 * • Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * Note:
 * • A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * • Only the filled cells need to be validated according to the mentioned rules.
 * Example 1:
 * Input: board =
 * [[&quot;5&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
 * ,[&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
 * ,[&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;]
 * ,[&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;]
 * ,[&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;]
 * ,[&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;]
 * ,[&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;]
 * ,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;]
 * ,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]]
 * Output: true
 * Example 2:
 * Input: board =
 * [[&quot;8&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
 * ,[&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
 * ,[&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;]
 * ,[&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;]
 * ,[&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;]
 * ,[&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;]
 * ,[&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;]
 * ,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;]
 * ,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8 . Since there are two 8&#39;s in the top left 3x3 sub-box, it is invalid.
 * Constraints:
 * • board.length == 9
 * • board[i].length == 9
 * • board[i][j] is a digit 1-9 or &#39;.&#39; .
 * 
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // We use 3 hashsets:
        // rows[i]  -> stores elements seen in row i
        // cols[j]  -> stores elements seen in column j
        // boxes[k] -> stores elements seen in 3x3 box k

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                char current = board[i][j];

                // Ignore empty cells
                if(current == '.') {
                    continue;
                }

                // Formula to identify box number
                int boxIndex = (i / 3) * 3 + (j / 3);

                // If already present anywhere -> invalid sudoku
                if(rows[i].count(current) ||
                   cols[j].count(current) ||
                   boxes[boxIndex].count(current)) {

                    return false;
                }

                // Mark current number as visited
                rows[i].insert(current);
                cols[j].insert(current);
                boxes[boxIndex].insert(current);
            }
        }

        return true;
    }
};