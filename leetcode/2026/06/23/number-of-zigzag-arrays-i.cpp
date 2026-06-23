/*
 * Problem: Number of ZigZag Arrays I
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/
 * Language: cpp
 * Topics: Dynamic Programming, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given three integers n , l , and r .
 * A ZigZag array of length n is defined as follows:
 * • Each element lies in the range [l, r] .
 * • No two adjacent elements are equal.
 * • No three consecutive elements form a strictly increasing or strictly decreasing sequence.
 * Return the total number of valid ZigZag arrays.
 * Since the answer may be large, return it modulo 10 9 + 7 .
 * A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
 * A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
 * Example 1:
 * Input: n = 3, l = 4, r = 5
 * Output: 2
 * Explanation:
 * There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5] :
 * • [4, 5, 4]
 * • [5, 4, 5] ​​​​​​​
 * Example 2:
 * Input: n = 3, l = 1, r = 3
 * Output: 10
 * Explanation:
 * There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3] :
 * • [1, 2, 1] , [1, 3, 1] , [1, 3, 2]
 * • [2, 1, 2] , [2, 1, 3] , [2, 3, 1] , [2, 3, 2]
 * • [3, 1, 2] , [3, 1, 3] , [3, 2, 3]
 * All arrays meet the ZigZag conditions.
 * Constraints:
 * • 3 <= n <= 2000
 * • 1 <= l < r <= 2000
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use dynamic programming: let dp[i][dir][x] be the count of length- i sequences ending at value x where dir is the required next comparison (0 = down, 1 = up).
 * Hint 2: If the required move is up (dir=1) do dp[i+1][0][y] += sum(dp[i][1][x]) for x ; if the required move is down (dir=0) do dp[i+1][1][y] += sum(dp[i][0][x]) for x > y .
 * Hint 3: Speed up with prefix/suffix sums so each layer updates in O( m ) instead of O( m 2 ); take values mod 10 9 +7 .
 * 
 */

class Solution {
public:
    const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;  // range size
        // dp arrays: up[i][val], down[i][val]
        vector<vector<int>> up(n + 1, vector<int>(m, 0));
        vector<vector<int>> down(n + 1, vector<int>(m, 0));

        // Base case: arrays of length 2
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < m; y++) {
                if (x == y) continue;
                if (x < y) up[2][y] = (up[2][y] + 1) % MOD;
                else down[2][y] = (down[2][y] + 1) % MOD;
            }
        }

        // Build DP for lengths 3..n
        for (int i = 3; i <= n; i++) {
            // prefix sums for fast range queries
            vector<int> prefUp(m + 1, 0), prefDown(m + 1, 0);

            for (int v = 0; v < m; v++) {
                prefUp[v + 1] = (prefUp[v] + up[i - 1][v]) % MOD;
                prefDown[v + 1] = (prefDown[v] + down[i - 1][v]) % MOD;
            }

            for (int y = 0; y < m; y++) {
                // up[i][y] = sum of down[i-1][x] for x < y
                up[i][y] = prefDown[y];

                // down[i][y] = sum of up[i-1][x] for x > y
                down[i][y] = ((prefUp[m] - prefUp[y + 1]) % MOD + MOD) % MOD;
            }
        }

        long long ans = 0;
        if (n == 1) {
            // Single element arrays are always valid
            ans = m;
        } else {
            for (int y = 0; y < m; y++) {
                ans = (ans + up[n][y] + down[n][y]) % MOD;
            }
        }

        return ans;
    }
};