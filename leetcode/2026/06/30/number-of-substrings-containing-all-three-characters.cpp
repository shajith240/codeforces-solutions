/*
 * Problem: Number of Substrings Containing All Three Characters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * Language: cpp
 * Topics: Hash Table, String, Sliding Window
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string s consisting only of characters a , b and c .
 * Return the number of substrings containing at least one occurrence of all these characters a , b and c .
 * Example 1:
 * Input: s = &quot;abcabc&quot;
 * Output: 10
 * Explanation: The substrings containing at least one occurrence of the characters a , b and c are &quot; abc &quot;, &quot; abca &quot;, &quot; abcab &quot;, &quot; abcabc &quot;, &quot; bca &quot;, &quot; bcab &quot;, &quot; bcabc &quot;, &quot; cab &quot;, &quot; cabc &quot; and &quot; abc &quot; ( again ) .
 * Example 2:
 * Input: s = &quot;aaacb&quot;
 * Output: 3
 * Explanation: The substrings containing at least one occurrence of the characters a , b and c are &quot; aaacb &quot;, &quot; aacb &quot; and &quot; acb &quot;.
 * Example 3:
 * Input: s = &quot;abc&quot;
 * Output: 1
 * Constraints:
 * • 3 <= s.length <= 5 x 10^4
 * • s only consists of a , b or c characters.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: For each position we simply need to find the first occurrence of a/b/c on or after this position.
 * Hint 2: So we can pre-compute three link-list of indices of each a, b, and c.
 * 
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int freq[3] = {0, 0, 0};

        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += (n - r);

                freq[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};