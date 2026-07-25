/*
 * Problem: Maximum Product of Two Digits
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-product-of-two-digits/
 * Language: cpp
 * Topics: Math, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a positive integer n .
 * Return the maximum product of any two digits in n .
 * Note: You may use the same digit twice if it appears more than once in n .
 * Example 1:
 * Input: n = 31
 * Output: 3
 * Explanation:
 * • The digits of n are [3, 1] .
 * • The possible products of any two digits are: 3 * 1 = 3 .
 * • The maximum product is 3.
 * Example 2:
 * Input: n = 22
 * Output: 4
 * Explanation:
 * • The digits of n are [2, 2] .
 * • The possible products of any two digits are: 2 * 2 = 4 .
 * • The maximum product is 4.
 * Example 3:
 * Input: n = 124
 * Output: 8
 * Explanation:
 * • The digits of n are [1, 2, 4] .
 * • The possible products of any two digits are: 1 * 2 = 2 , 1 * 4 = 4 , 2 * 4 = 8 .
 * • The maximum product is 8.
 * Constraints:
 * • 10 <= n <= 10 9
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use brute force
 * 
 */

class Solution {
public:

    int maxProduct(int n) {
        //first extract digits and in that process get the first and second max and just return their sum
        int firstMax = 0;
        int secondMax = 0;
        while(n > 0){
            int digit = n % 10;

            if(digit >= firstMax){
                secondMax = firstMax;
                firstMax = digit;
            }
            else if(digit >= secondMax && digit != firstMax){
                secondMax = digit;
            }
            n = n / 10;
        }

        return firstMax * secondMax;
    }
};