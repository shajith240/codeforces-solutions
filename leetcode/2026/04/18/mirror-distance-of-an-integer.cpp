/*
 * Problem: Mirror Distance of an Integer
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/mirror-distance-of-an-integer/
 * Language: cpp
 * Topics: Math
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer n .
 * Define its mirror distance as: abs(n - reverse(n)) ​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n .
 * Return an integer denoting the mirror distance of n ​​​​​​​.
 * abs(x) denotes the absolute value of x .
 * Example 1:
 * Input: n = 25
 * Output: 27
 * Explanation:
 * • reverse(25) = 52 .
 * • Thus, the answer is abs(25 - 52) = 27 .
 * Example 2:
 * Input: n = 10
 * Output: 9
 * Explanation:
 * • reverse(10) = 01 which is 1.
 * • Thus, the answer is abs(10 - 1) = 9 .
 * Example 3:
 * Input: n = 7
 * Output: 0
 * Explanation:
 * • reverse(7) = 7 .
 * • Thus, the answer is abs(7 - 7) = 0 .
 * Constraints:
 * • 1 <= n <= 10 9
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Simulate as described
 * 
 */

class Solution {
public:

    int reverse(int x){
        int digit = 1;
        int ans = 0;
        while(x > 0){
            digit = x % 10;
            ans = ans * 10 + digit;
            x = x / 10;
        }
        return ans;
    }

    int mirrorDistance(int n) {
        int n2 = reverse(n);
        return abs(n2 - n);
    }
};