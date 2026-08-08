/*
 * Problem: Find the Lexicographically Smallest Valid Sequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
 * Language: cpp
 * Topics: Two Pointers, String, Dynamic Programming, Greedy
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given two strings word1 and word2 .
 * A string x is called almost equal to y if you can change at most one character in x to make it identical to y .
 * A sequence of indices seq is called valid if:
 * • The indices are sorted in ascending order.
 * • Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2 .
 * Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.
 * Note that the answer must represent the lexicographically smallest array , not the corresponding string formed by those indices.
 * Example 1:
 * Input: word1 = &quot;vbcca&quot;, word2 = &quot;abc&quot;
 * Output: [0,1,2]
 * Explanation:
 * The lexicographically smallest valid sequence of indices is [0, 1, 2] :
 * • Change word1[0] to &#39;a&#39; .
 * • word1[1] is already &#39;b&#39; .
 * • word1[2] is already &#39;c&#39; .
 * Example 2:
 * Input: word1 = &quot;bacdc&quot;, word2 = &quot;abc&quot;
 * Output: [1,2,4]
 * Explanation:
 * The lexicographically smallest valid sequence of indices is [1, 2, 4] :
 * • word1[1] is already &#39;a&#39; .
 * • Change word1[2] to &#39;b&#39; .
 * • word1[4] is already &#39;c&#39; .
 * Example 3:
 * Input: word1 = &quot;aaaaaa&quot;, word2 = &quot;aaabc&quot;
 * Output: []
 * Explanation:
 * There is no valid sequence of indices.
 * Example 4:
 * Input: word1 = &quot;abc&quot;, word2 = &quot;ab&quot;
 * Output: [0,1]
 * Constraints:
 * • 1 <= word2.length < word1.length <= 3 * 10 5
 * • word1 and word2 consist only of lowercase English letters.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Let dp[i] be the longest suffix of word2 that exists as a subsequence of suffix of the substring of word1 starting at index i .
 * Hint 2: If dp[i + 1] and word1[i] == word2[m - dp[i + 1] - 1] , dp[i] = dp[i + 1] + 1 . Otherwise, dp[i] = dp[i + 1] .
 * Hint 3: For each index i , greedily select characters using the dp array to know whether a solution exists.
 * 
 */

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = first unmatched position in word2 after greedily
        // matching suffix starting from word1[i]
        vector<int> suf(n + 1, m);
        int j = m - 1;

        suf[n] = m;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans;
        bool used = false;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!used) {
                // Can we spend our mismatch here?
                // Remaining suffix of word2 starts at j+1.
                // Remaining suffix of word1 starts at i+1.
                if (suf[i + 1] <= j + 1) {
                    used = true;
                    ans.push_back(i);
                    j++;
                }
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};