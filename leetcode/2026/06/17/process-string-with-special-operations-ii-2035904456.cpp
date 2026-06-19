/*
 * Problem: Process String with Special Operations II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/process-string-with-special-operations-ii/
 * Language: cpp
 * Topics: String, Simulation
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a string s consisting of lowercase English letters and the special characters: &#39;*&#39; , &#39;#&#39; , and &#39;%&#39; .
 * You are also given an integer k .
 * Build a new string result by processing s according to the following rules from left to right:
 * • If the letter is a lowercase English letter append it to result .
 * • A &#39;*&#39; removes the last character from result , if it exists.
 * • A &#39;#&#39; duplicates the current result and appends it to itself.
 * • A &#39;%&#39; reverses the current result .
 * Return the k th character of the final string result . If k is out of the bounds of result , return &#39;.&#39; .
 * Example 1:
 * Input: s = &quot;a#b%*&quot;, k = 1
 * Output: &quot;a&quot;
 * Explanation:
 * i
 * s[i]
 * Operation
 * Current result
 * 0
 * &#39;a&#39;
 * Append &#39;a&#39;
 * &quot;a&quot;
 * 1
 * &#39;#&#39;
 * Duplicate result
 * &quot;aa&quot;
 * 2
 * &#39;b&#39;
 * Append &#39;b&#39;
 * &quot;aab&quot;
 * 3
 * &#39;%&#39;
 * Reverse result
 * &quot;baa&quot;
 * 4
 * &#39;*&#39;
 * Remove the last character
 * &quot;ba&quot;
 * The final result is &quot;ba&quot; . The character at index k = 1 is &#39;a&#39; .
 * Example 2:
 * Input: s = &quot;cd%#*#&quot;, k = 3
 * Output: &quot;d&quot;
 * Explanation:
 * i
 * s[i]
 * Operation
 * Current result
 * 0
 * &#39;c&#39;
 * Append &#39;c&#39;
 * &quot;c&quot;
 * 1
 * &#39;d&#39;
 * Append &#39;d&#39;
 * &quot;cd&quot;
 * 2
 * &#39;%&#39;
 * Reverse result
 * &quot;dc&quot;
 * 3
 * &#39;#&#39;
 * Duplicate result
 * &quot;dcdc&quot;
 * 4
 * &#39;*&#39;
 * Remove the last character
 * &quot;dcd&quot;
 * 5
 * &#39;#&#39;
 * Duplicate result
 * &quot;dcddcd&quot;
 * The final result is &quot;dcddcd&quot; . The character at index k = 3 is &#39;d&#39; .
 * Example 3:
 * Input: s = &quot;z*#&quot;, k = 0
 * Output: &quot;.&quot;
 * Explanation:
 * i
 * s[i]
 * Operation
 * Current result
 * 0
 * &#39;z&#39;
 * Append &#39;z&#39;
 * &quot;z&quot;
 * 1
 * &#39;*&#39;
 * Remove the last character
 * &quot;&quot;
 * 2
 * &#39;#&#39;
 * Duplicate the string
 * &quot;&quot;
 * The final result is &quot;&quot; . Since index k = 0 is out of bounds, the output is &#39;.&#39; .
 * Constraints:
 * • 1 <= s.length <= 10 5
 * • s consists of only lowercase English letters and special characters &#39;*&#39; , &#39;#&#39; , and &#39;%&#39; .
 * • 0 <= k <= 10 15
 * • The length of result after processing s will not exceed 10 15 .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Track the length of the string after each operation on s .
 * Hint 2: Walk backwards through s , undoing each # by using modulus on the tracked lengths, and undoing each % by mirroring across the midpoint, to pinpoint the k th character.
 * 
 */

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long L = 0;

        for (char& ch : s) {
            if (ch == '#') {
                L *= 2;
            } else if (ch == '%') {
                continue;
            } else if (ch == '*') {
                if (L > 0) {
                    L--;
                }
            } else {
                L++;
            }
        }

        if (k >= L) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '%') {
                // no change in l
                k = L - k - 1;
            } else if (s[i] == '*') {
                L++;
            } else if (s[i] == '#') {
                L = L / 2;
                k = (k >= L) ? k - L : k;
            } else {
                L--;
                if (k == L) {
                    return s[i];
                }
            }
        }

        return '.';
    }
};