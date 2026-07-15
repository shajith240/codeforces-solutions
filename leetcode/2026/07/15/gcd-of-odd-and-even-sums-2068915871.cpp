/*
 * Problem: GCD of Odd and Even Sums
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
 * Language: cpp
 * Topics: Math, Number Theory
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer n . Your task is to compute the GCD (greatest common divisor) of two values:
 * •
 * sumOdd : the sum of the smallest n positive odd numbers.
 * •
 * sumEven : the sum of the smallest n positive even numbers.
 * Return the GCD of sumOdd and sumEven .
 * Example 1:
 * Input: n = 4
 * Output: 4
 * Explanation:
 * • Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
 * • Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
 * Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4 .
 * Example 2:
 * Input: n = 5
 * Output: 5
 * Explanation:
 * • Sum of the first 5 odd numbers sumOdd = 1 + 3 + 5 + 7 + 9 = 25
 * • Sum of the first 5 even numbers sumEven = 2 + 4 + 6 + 8 + 10 = 30
 * Hence, GCD(sumOdd, sumEven) = GCD(25, 30) = 5 .
 * Constraints:
 * • 1 <= n <= 10​​​​​​​00
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: The first n odd numbers sum to n * n
 * Hint 2: First n even numbers sum to n * (n + 1)
 * Hint 3: gcd(n, n + 1) = 1 , so the answer is n
 * 
 */

class Solution {
public:

    int gcd(int a,int b){
        if(a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        if(a == b){
            return a;
        }

        if(a > b){
            return gcd(a-b,b);
        }
        
        return gcd(a,b - a);
    }


    int gcdOfOddEvenSums(int n) {
        
        int sumOdd = n * n ;
        int sumEven = n * (n + 1);
        return gcd(sumOdd,sumEven);
    }
};