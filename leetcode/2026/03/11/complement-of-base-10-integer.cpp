/*
 * Problem: Complement of Base 10 Integer
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/complement-of-base-10-integer/
 * Language: cpp
 * Topics: Bit Manipulation
 * 
 * ── Problem ────────────────────────────────────────────
 * The complement of an integer is the integer you get when you flip all the 0 &#39;s to 1 &#39;s and all the 1 &#39;s to 0 &#39;s in its binary representation.
 * • For example, The integer 5 is &quot;101&quot; in binary and its complement is &quot;010&quot; which is the integer 2 .
 * Given an integer n , return its complement .
 * Example 1:
 * Input: n = 5
 * Output: 2
 * Explanation: 5 is &quot;101&quot; in binary, with complement &quot;010&quot; in binary, which is 2 in base-10.
 * Example 2:
 * Input: n = 7
 * Output: 0
 * Explanation: 7 is &quot;111&quot; in binary, with complement &quot;000&quot; in binary, which is 0 in base-10.
 * Example 3:
 * Input: n = 10
 * Output: 5
 * Explanation: 10 is &quot;1010&quot; in binary, with complement &quot;0101&quot; in binary, which is 5 in base-10.
 * Constraints:
 * • 0 <= n < 10 9
 * Note: This question is the same as 476: https://leetcode.com/problems/number-complement/
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: A binary number plus its complement will equal 111....111 in binary. Also, N = 0 is a corner case.
 * 
 */

class Solution {
public:
    string DecimalToBinary(int n) {
        if(n == 0){
            return "0";
        }
        int digit = 0;
        string rem = "";
        
        while (n > 0) {
            digit = n % 2;
            if (digit == 1) {
                rem += '1';
            } else {
                rem += '0';
            }
            n = n / 2;
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }

    int BinaryToDecimal(string s) {
        int sum = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            sum += (s[(n - i - 1) ] - '0' )* (1 << i );
        }
        return sum;
    }

    int bitwiseComplement(int n) {
        string ans = DecimalToBinary(n);

        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] == '1') {
                ans[i] = '0';
            } else {
                ans[i] = '1';
            }
        }

        return BinaryToDecimal(ans);
    }
};