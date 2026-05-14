/*
 * Problem: Minimum Window Substring
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/minimum-window-substring/
 * Language: cpp
 * Topics: Hash Table, String, Sliding Window
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t ( including duplicates ) is included in the window . If there is no such substring, return the empty string &quot;&quot; .
 * The testcases will be generated such that the answer is unique .
 * Example 1:
 * Input: s = &quot;ADOBECODEBANC&quot;, t = &quot;ABC&quot;
 * Output: &quot;BANC&quot;
 * Explanation: The minimum window substring &quot;BANC&quot; includes &#39;A&#39;, &#39;B&#39;, and &#39;C&#39; from string t.
 * Example 2:
 * Input: s = &quot;a&quot;, t = &quot;a&quot;
 * Output: &quot;a&quot;
 * Explanation: The entire string s is the minimum window.
 * Example 3:
 * Input: s = &quot;a&quot;, t = &quot;aa&quot;
 * Output: &quot;&quot;
 * Explanation: Both &#39;a&#39;s from t must be included in the window.
 * Since the largest window of s only has one &#39;a&#39;, return empty string.
 * Constraints:
 * • m == s.length
 * • n == t.length
 * • 1 <= m, n <= 10 5
 * • s and t consist of uppercase and lowercase English letters.
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use two pointers to create a window of letters in s, which would have all the characters from t.
 * Hint 2: Expand the right pointer until all the characters of t are covered.
 * Hint 3: Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.
 * Hint 4: Continue expanding the right and left pointers until you reach the end of s.
 * 
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        unordered_map<char, int> mp;

        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }

        int RequiredCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;
        int i = 0;
        int j = 0;
        while (j < n) {

            char ch = s[j];
            if (mp[ch] > 0) {
                RequiredCount--;
            }

            mp[ch]--;

            while (RequiredCount == 0) {
                // shrinking
                int windowSize = j - i + 1;

                if (minWindowSize > windowSize) {
                    minWindowSize = windowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    RequiredCount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i,minWindowSize);
    }
};