/*
 * Problem: Maximize Active Section with Trade I
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/
 * Language: cpp
 * Topics: String, Enumeration
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a binary string s of length n , where:
 * • &#39;1&#39; represents an active section.
 * • &#39;0&#39; represents an inactive section.
 * You can perform at most one trade to maximize the number of active sections in s . In a trade, you:
 * • Convert a contiguous block of &#39;1&#39; s that is surrounded by &#39;0&#39; s to all &#39;0&#39; s.
 * • Afterward, convert a contiguous block of &#39;0&#39; s that is surrounded by &#39;1&#39; s to all &#39;1&#39; s.
 * Return the maximum number of active sections in s after making the optimal trade.
 * Note: Treat s as if it is augmented with a &#39;1&#39; at both ends, forming t = &#39;1&#39; + s + &#39;1&#39; . The augmented &#39;1&#39; s do not contribute to the final count.
 * Example 1:
 * Input: s = &quot;01&quot;
 * Output: 1
 * Explanation:
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 1.
 * Example 2:
 * Input: s = &quot;0100&quot;
 * Output: 4
 * Explanation:
 * • String &quot;0100&quot; &rarr; Augmented to &quot;101001&quot; .
 * • Choose &quot;0100&quot; , convert &quot;10 1 001&quot; &rarr; &quot;1 0000 1&quot; &rarr; &quot;1 1111 1&quot; .
 * • The final string without augmentation is &quot;1111&quot; . The maximum number of active sections is 4.
 * Example 3:
 * Input: s = &quot;1000100&quot;
 * Output: 7
 * Explanation:
 * • String &quot;1000100&quot; &rarr; Augmented to &quot;110001001&quot; .
 * • Choose &quot;000100&quot; , convert &quot;11000 1 001&quot; &rarr; &quot;11 000000 1&quot; &rarr; &quot;11 111111 1&quot; .
 * • The final string without augmentation is &quot;1111111&quot; . The maximum number of active sections is 7.
 * Example 4:
 * Input: s = &quot;01010&quot;
 * Output: 4
 * Explanation:
 * • String &quot;01010&quot; &rarr; Augmented to &quot;1010101&quot; .
 * • Choose &quot;010&quot; , convert &quot;10 1 0101&quot; &rarr; &quot;1 000 101&quot; &rarr; &quot;1 111 101&quot; .
 * • The final string without augmentation is &quot;11110&quot; . The maximum number of active sections is 4.
 * Constraints:
 * • 1 <= n == s.length <= 10 5
 * • s[i] is either &#39;0&#39; or &#39;1&#39;
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Split the string into several zero-one segments.
 * Hint 2: For each one-segment, if it has two neighbors (i.e., it is surrounded by two zero-segments), the total sum of their lengths is one of the candidates for delta .
 * Hint 3: Find the maximum delta and add it to the total number of ones in the string.
 * 
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int>> runs;

        int originalOnes = 0;
        int cnt = 1;
        string t = "1";
        t += s;
        t += '1';

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                originalOnes++;
            }
        }

        for (int i = 1; i < t.length(); i++) {
            if (t[i - 1] == t[i]) {
                cnt++;
            } else {
                runs.push_back({t[i - 1], cnt});
                cnt = 1;
            }
        }

        runs.push_back({t.back(), cnt});

        // now we wil count the max gain we are getting on the choosing one runs

        int maxgain = originalOnes;
        for (int i = 1; i < runs.size() - 1; i++) {
            if (runs[i].first == '1') {
                int currentgain = 0;
                if (runs[i - 1].first == '0' && runs[i + 1].first == '0') {
                    currentgain =
                        originalOnes + runs[i - 1].second + runs[i + 1].second;
                    maxgain = max(maxgain, currentgain);
                }
            }
        }

        return maxgain;
    }
};