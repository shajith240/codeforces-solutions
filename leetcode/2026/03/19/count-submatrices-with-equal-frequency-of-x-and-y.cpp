/*
 * Problem: Count Submatrices With Equal Frequency of X and Y
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
 * Language: cpp
 * Topics: Array, Matrix, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a 2D character matrix grid , where grid[i][j] is either &#39;X&#39; , &#39;Y&#39; , or &#39;.&#39; , return the number of submatrices that contain:
 * • grid[0][0]
 * • an equal frequency of &#39;X&#39; and &#39;Y&#39; .
 * • at least one &#39;X&#39; .
 * Example 1:
 * Input: grid = [[&quot;X&quot;,&quot;Y&quot;,&quot;.&quot;],[&quot;Y&quot;,&quot;.&quot;,&quot;.&quot;]]
 * Output: 3
 * Explanation:
 * Example 2:
 * Input: grid = [[&quot;X&quot;,&quot;X&quot;],[&quot;X&quot;,&quot;Y&quot;]]
 * Output: 0
 * Explanation:
 * No submatrix has an equal frequency of &#39;X&#39; and &#39;Y&#39; .
 * Example 3:
 * Input: grid = [[&quot;.&quot;,&quot;.&quot;],[&quot;.&quot;,&quot;.&quot;]]
 * Output: 0
 * Explanation:
 * No submatrix has at least one &#39;X&#39; .
 * Constraints:
 * • 1 <= grid.length, grid[i].length <= 1000
 * • grid[i][j] is either &#39;X&#39; , &#39;Y&#39; , or &#39;.&#39; .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Replace ’X’ with 1, ’Y’ with -1 and ’.’ with 0.
 * Hint 2: You need to find how many submatrices grid[0..x][0..y] have a sum of 0 and at least one ’X’ .
 * Hint 3: Use prefix sum to calculate submatrices sum.
 * 
 */

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<int>> cumSumx(m,vector<int>(n,0));
        vector<vector<int>> cumSumy(m,vector<int>(n,0));

        
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j  < n  ;j++){

                cumSumx[i][j] = (grid[i][j] == 'X');
                cumSumy[i][j] = (grid[i][j] == 'Y');
                
                if(i - 1 >= 0){
                cumSumx[i][j] += cumSumx[i - 1][j];
                cumSumy[i][j] += cumSumy[i - 1][j];
                }

                if(j - 1 >= 0){
                cumSumx[i][j] += cumSumx[i][j - 1];
                cumSumy[i][j] += cumSumy[i][j - 1];
                }

                if(i - 1 >= 0 && j - 1 >=0){
                cumSumx[i][j] -= cumSumx[i - 1][j - 1];
                cumSumy[i][j] -= cumSumy[i - 1][j - 1];
                }


                if(cumSumx[i][j] == cumSumy[i][j] && cumSumx[i][j] > 0){
                    count++;
                }
            }
        }
        return count;
    }
};