/*
 * Problem: Check if Every Row and Column Contains All Numbers
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
 * Language: cpp
 * Topics: Array, Hash Table, Matrix
 * 
 * ── Problem ────────────────────────────────────────────
 * An n x n matrix is valid if every row and every column contains all the integers from 1 to n ( inclusive ).
 * Given an n x n integer matrix matrix , return true if the matrix is valid . Otherwise, return false .
 * Example 1:
 * Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
 * Output: true
 * Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
 * Hence, we return true.
 * Example 2:
 * Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
 * Output: false
 * Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
 * Hence, we return false.
 * Constraints:
 * • n == matrix.length == matrix[i].length
 * • 1 <= n <= 100
 * • 1 <= matrix[i][j] <= n
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use for loops to check each row for every number from 1 to n. Similarly, do the same for each column.
 * Hint 2: For each check, you can keep a set of the unique elements in the checked row/col. By the end of the check, the size of the set should be n.
 * 
 */

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0 ; i < n ; i++){
            unordered_set<int> rowset;
            unordered_set<int> colset;

            for(int j = 0 ; j < n ; j++){
                rowset.insert(matrix[i][j]);
                colset.insert(matrix[j][i]);
            }

            if(rowset.size() != n || colset.size() != n){
                return false;
            }
        }
        return true;
    }
};