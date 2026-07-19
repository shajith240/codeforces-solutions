/*
 * Problem: Smallest Subsequence of Distinct Characters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * Language: cpp
 * Topics: String, Stack, Greedy, Monotonic Stack
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string s , return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once .
 * Example 1:
 * Input: s = &quot;bcabc&quot;
 * Output: &quot;abc&quot;
 * Example 2:
 * Input: s = &quot;cbacdcbc&quot;
 * Output: &quot;acdb&quot;
 * Constraints:
 * • 1 <= s.length <= 1000
 * • s consists of lowercase English letters.
 * Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Greedily try to add one missing character. How to check if adding some character will not cause problems ? Use bit-masks to check whether you will be able to complete the sub-sequence if you add the character at some index i.
 * 
 */

class Solution {
public:
    string smallestSubsequence(string s) {

        // what is the plan
        // the plan is to traverse the string left to right and add the char to
        // the stack but before that check that if the st.top() is greater than
        // the current char and we have the st.top() freq greater than before so
        // we pop it and push the current char to the stack

        // 1.we have to build a freq map of the char in the string s
        // 2.we have to have a visited array to store the visited status of the
        // char 3.and want a stack for this to store the answer so the algo will
        // be like for each char from left to right we have to check that the
        // st.top() > current char && freq > 0 then st.pop() st.add(curent); and
        // freq-- or just add it and freq--;

        // but we have to do this while the condition satisfies in the stack so
        // while loop
        int n = s.length();
        bool visited[26] = {0};

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        stack<char> st;

        for (int i = 0; i < n; i++) {
            mp[s[i]]--;

            if (visited[s[i] - 'a'] == true) {
                continue;
            };

            while (!st.empty() && mp[st.top()] > 0 &&
                   st.top() - 'a' > s[i] - 'a') {
                char current = st.top();
                st.pop();
                visited[current - 'a'] = false;
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};