/*
 * Problem: Smallest Palindromic Rearrangement I
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 * Language: cpp
 * Topics: String, Sorting, Counting Sort
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a palindromic string s .
 * Return the lexicographically smallest palindromic permutation of s .
 * Example 1:
 * Input: s = &quot;z&quot;
 * Output: &quot;z&quot;
 * Explanation:
 * A string of only one character is already the lexicographically smallest palindrome.
 * Example 2:
 * Input: s = &quot;babab&quot;
 * Output: &quot;abbba&quot;
 * Explanation:
 * Rearranging &quot;babab&quot; &rarr; &quot;abbba&quot; gives the smallest lexicographic palindrome.
 * Example 3:
 * Input: s = &quot;daccad&quot;
 * Output: &quot;acddca&quot;
 * Explanation:
 * Rearranging &quot;daccad&quot; &rarr; &quot;acddca&quot; gives the smallest lexicographic palindrome.
 * Constraints:
 * • 1 <= s.length <= 10 5
 * • s consists of lowercase English letters.
 * • s is guaranteed to be palindromic.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Consider a palindrome as composed of two mirror-image halves.
 * Hint 2: Construct one half (using s ), and then the other half is its reverse to obtain the lexicographically smallest permutation.
 * 
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        vector<int> freq(26, 0);

        string ans = "";
        char middle = '\0';
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        string left = "";
        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2 != 0) {
                middle = (char)(i + 'a');
            }
            for(int j = 0 ;  j < freq[i] / 2 ; j++) {
                left += (char)(i + 'a');
            }
        }
        string temp = left;
        reverse(temp.begin(), temp.end());
        if (n % 2 == 0) {
            ans = left + temp;
            return ans;
        }
        ans = left + middle + temp;
        return ans;
    }
};