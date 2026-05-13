/*
 * Problem: Longest Repeating Character Replacement
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 * Language: cpp
 * Topics: Hash Table, String, Sliding Window
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a string s and an integer k . You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
 * Return the length of the longest substring containing the same letter you can get after performing the above operations .
 * Example 1:
 * Input: s = &quot;ABAB&quot;, k = 2
 * Output: 4
 * Explanation: Replace the two &#39;A&#39;s with two &#39;B&#39;s or vice versa.
 * Example 2:
 * Input: s = &quot;AABABBA&quot;, k = 1
 * Output: 4
 * Explanation: Replace the one &#39;A&#39; in the middle with &#39;B&#39; and form &quot;AABBBBA&quot;.
 * The substring &quot;BBBB&quot; has the longest repeating letters, which is 4.
 * There may exists other ways to achieve this answer too.
 * Constraints:
 * • 1 <= s.length <= 10 5
 * • s consists of only uppercase English letters.
 * • 0 <= k <= s.length
 * 
 */

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> freq;

        int i = 0;

        int maxfreq = 0;

        int maxlen = 0;

        for(int j = 0; j < s.length(); j++) {

            // Expand window
            freq[s[j]]++;

            // Track highest frequency character
            maxfreq = max(maxfreq, freq[s[j]]);

            // If window invalid, shrink from left
            while((j - i + 1) - maxfreq > k) {

                freq[s[i]]--;

                i++;
            }

            // Update answer
            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};