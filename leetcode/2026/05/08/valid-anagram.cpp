/*
 * Problem: Valid Anagram
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-anagram/
 * Language: cpp
 * Topics: Hash Table, String, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two strings s and t , return true if t is an anagram of s , and false otherwise.
 * Example 1:
 * Input: s = &quot;anagram&quot;, t = &quot;nagaram&quot;
 * Output: true
 * Example 2:
 * Input: s = &quot;rat&quot;, t = &quot;car&quot;
 * Output: false
 * Constraints:
 * • 1 <= s.length, t.length <= 5 * 10 4
 * • s and t consist of lowercase English letters.
 * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 * 
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1 != n2){
            return false;
        }
        
        int freq[26] = {0};

        for(int i = 0 ; i < n1 ; i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0 ; i < n2 ; i++){
            freq[t[i] - 'a']--;
        }

        for(int i = 0 ; i < 26 ;i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};