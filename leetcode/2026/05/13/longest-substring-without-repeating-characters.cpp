/*
 * Problem: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Language: cpp
 * Topics: Hash Table, String, Sliding Window
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string s , find the length of the longest substring without duplicate characters.
 * Example 1:
 * Input: s = &quot;abcabcbb&quot;
 * Output: 3
 * Explanation: The answer is &quot;abc&quot;, with the length of 3. Note that &quot;bca&quot; and &quot;cab&quot; are also correct answers.
 * Example 2:
 * Input: s = &quot;bbbbb&quot;
 * Output: 1
 * Explanation: The answer is &quot;b&quot;, with the length of 1.
 * Example 3:
 * Input: s = &quot;pwwkew&quot;
 * Output: 3
 * Explanation: The answer is &quot;wke&quot;, with the length of 3.
 * Notice that the answer must be a substring, &quot;pwke&quot; is a subsequence and not a substring.
 * Constraints:
 * • 0 <= s.length <= 5 * 10 4
 * • s consists of English letters, digits, symbols and spaces.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Since maximum string size is at most 26, generate and check all possible substrings with length at most 26.
 * 
 */

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int i = 0;

        int maxLen = 0;

        for(int j = 0; j < s.length(); j++) {

            // Duplicate found
            while(st.count(s[j])) {

                st.erase(s[i]);

                i++;
            }

            st.insert(s[j]);

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};