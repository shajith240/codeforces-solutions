/*
 * Problem: String to Integer (atoi)
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 * Language: cpp
 * Topics: String
 * 
 * ── Problem ────────────────────────────────────────────
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 * The algorithm for myAtoi(string s) is as follows:
 * • Whitespace : Ignore any leading whitespace ( &quot; &quot; ).
 * • Signedness : Determine the sign by checking if the next character is &#39;-&#39; or &#39;+&#39; , assuming positivity if neither present.
 * • Conversion : Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
 * • Rounding : If the integer is out of the 32-bit signed integer range [-2 31 , 2 31 - 1] , then round the integer to remain in the range. Specifically, integers less than -2 31 should be rounded to -2 31 , and integers greater than 2 31 - 1 should be rounded to 2 31 - 1 .
 * Return the integer as the final result.
 * Example 1:
 * Input: s = &quot;42&quot;
 * Output: 42
 * Explanation:
 * The underlined characters are what is read in and the caret is the current reader position.
 * Step 1: &quot;42&quot; (no characters read because there is no leading whitespace)
 * ^
 * Step 2: &quot;42&quot; (no characters read because there is neither a &#39;-&#39; nor &#39;+&#39;)
 * ^
 * Step 3: &quot; 42 &quot; (&quot;42&quot; is read in)
 * ^
 * Example 2:
 * Input: s = &quot; -042&quot;
 * Output: -42
 * Explanation:
 * Step 1: &quot; -042&quot; (leading whitespace is read and ignored)
 * ^
 * Step 2: &quot; - 042&quot; (&#39;-&#39; is read, so the result should be negative)
 * ^
 * Step 3: &quot; - 042 &quot; (&quot;042&quot; is read in, leading zeros ignored in the result)
 * ^
 * Example 3:
 * Input: s = &quot;1337c0d3&quot;
 * Output: 1337
 * Explanation:
 * Step 1: &quot;1337c0d3&quot; (no characters read because there is no leading whitespace)
 * ^
 * Step 2: &quot;1337c0d3&quot; (no characters read because there is neither a &#39;-&#39; nor &#39;+&#39;)
 * ^
 * Step 3: &quot; 1337 c0d3&quot; (&quot;1337&quot; is read in; reading stops because the next character is a non-digit)
 * ^
 * Example 4:
 * Input: s = &quot;0-1&quot;
 * Output: 0
 * Explanation:
 * Step 1: &quot;0-1&quot; (no characters read because there is no leading whitespace)
 * ^
 * Step 2: &quot;0-1&quot; (no characters read because there is neither a &#39;-&#39; nor &#39;+&#39;)
 * ^
 * Step 3: &quot; 0 -1&quot; (&quot;0&quot; is read in; reading stops because the next character is a non-digit)
 * ^
 * Example 5:
 * Input: s = &quot;words and 987&quot;
 * Output: 0
 * Explanation:
 * Reading stops at the first non-digit character &#39;w&#39;.
 * Constraints:
 * • 0 <= s.length <= 200
 * • s consists of English letters (lower-case and upper-case), digits ( 0-9 ), &#39; &#39; , &#39;+&#39; , &#39;-&#39; , and &#39;.&#39; .
 * 
 */

class Solution {
public:
    int myAtoi(string s) {

        int value = 0;

        int n = s.length();
        int i = 0;
        bool isnegetive = false;

        while (i < n && isspace(s[i])) {
            i++;
        }

        if (i == n) {
            return 0;
        }

        if (s[i] == '-') {
            isnegetive = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        else if (!isdigit(s[i])) {
            return 0;
        }

        if (i == n) {
            return 0;
        }

        while (i < n && s[i] == '0') {
            i++;
        }

        if (i == n) {
            return 0;
        }

        int max = INT_MAX / 10;
        int min = INT_MIN / 10;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (value > INT_MAX / 10 || (value == INT_MAX / 10 && digit > 7))
                return INT_MAX;
            if (value < INT_MIN / 10 || (value == INT_MIN / 10 && digit > 8))
                return INT_MIN;
                

            if (isnegetive) {
                value = value * 10 + (-digit);
            } else {
                value = value * 10 + digit;
            }
            i++;
        }

        return value;
    }
};