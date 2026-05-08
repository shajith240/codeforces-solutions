/*
 * Problem: Count Good Numbers
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/count-good-numbers/
 * Language: cpp
 * Topics: Math, Recursion
 * 
 * ── Problem ────────────────────────────────────────────
 * A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime ( 2 , 3 , 5 , or 7 ).
 * • For example, &quot;2582&quot; is good because the digits ( 2 and 8 ) at even positions are even and the digits ( 5 and 2 ) at odd positions are prime. However, &quot;3245&quot; is not good because 3 is at an even index but is not even.
 * Given an integer n , return the total number of good digit strings of length n . Since the answer may be large, return it modulo 10 9 + 7 .
 * A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 * Example 1:
 * Input: n = 1
 * Output: 5
 * Explanation: The good numbers of length 1 are &quot;0&quot;, &quot;2&quot;, &quot;4&quot;, &quot;6&quot;, &quot;8&quot;.
 * Example 2:
 * Input: n = 4
 * Output: 400
 * Example 3:
 * Input: n = 50
 * Output: 564908303
 * Constraints:
 * • 1 <= n <= 10 15
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Is there a formula we can use to find the count of all the good numbers?
 * Hint 2: Exponentiation can be done very fast if we looked at the binary bits of n.
 * 
 */

class Solution {
public:
    

    long long MOD = 1e9 + 7;
    long long solve(long long  x , long long n){
        if(n == 0){
            return 1;
        }

        long long half = solve(x,n / 2);

        long long half_squared = (half * half) % MOD;

        if(n % 2 == 0){
            return half_squared;
        }
        else{
            return( x * half_squared) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        
      long long odd_positions = n / 2;
      long long even_positions = (n+1) / 2;

      long long even_choices = solve(5,even_positions);
      long long odd_choices = solve(4,odd_positions);

      return (even_choices * odd_choices) % MOD;
    }
};