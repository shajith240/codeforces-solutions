/*
 * Problem: Process String with Special Operations I
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/process-string-with-special-operations-i/
 * Language: cpp
 * Topics: String, Simulation
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a string s consisting of lowercase English letters and the special characters: * , # , and % .
 * Build a new string result by processing s according to the following rules from left to right:
 * • If the letter is a lowercase English letter append it to result .
 * • A &#39;*&#39; removes the last character from result , if it exists.
 * • A &#39;#&#39; duplicates the current result and appends it to itself.
 * • A &#39;%&#39; reverses the current result .
 * Return the final string result after processing all characters in s .
 * Example 1:
 * Input: s = &quot;a#b%*&quot;
 * Output: &quot;ba&quot;
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
 * Thus, the final result is &quot;ba&quot; .
 * Example 2:
 * Input: s = &quot;z*#&quot;
 * Output: &quot;&quot;
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
 * Thus, the final result is &quot;&quot; .
 * Constraints:
 * • 1 <= s.length <= 20
 * • s consists of only lowercase English letters and special characters * , # , and % .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Simulate as described
 * 
 */

class Solution {
public:
    string result = "";

    void removeThelast() {
        if (!result.empty())
            result.pop_back();
    }

    string processStr(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removeThelast();
            } else if (s[i] == '#') {
                result = result + result;
            } else if (s[i] == '%') {
                reverse(result.begin(), result.end());
            } else {
                result += s[i];
            }
        }

        return result;
    }
};