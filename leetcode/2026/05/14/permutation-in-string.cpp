/*
 * Problem: Permutation in String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/permutation-in-string/
 * Language: cpp
 * Topics: Hash Table, Two Pointers, String, Sliding Window
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two strings s1 and s2 , return true if s2 contains a permutation of s1 , or false otherwise.
 * In other words, return true if one of s1 &#39;s permutations is the substring of s2 .
 * Example 1:
 * Input: s1 = &quot;ab&quot;, s2 = &quot;eidbaooo&quot;
 * Output: true
 * Explanation: s2 contains one permutation of s1 (&quot;ba&quot;).
 * Example 2:
 * Input: s1 = &quot;ab&quot;, s2 = &quot;eidboaoo&quot;
 * Output: false
 * Constraints:
 * • 1 <= s1.length, s2.length <= 10 4
 * • s1 and s2 consist of lowercase English letters.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Obviously, brute force will result in TLE. Think of something else.
 * Hint 2: How will you check whether one string is a permutation of another string?
 * Hint 3: One way is to sort the string and then compare. But, Is there a better way?
 * Hint 4: If one string is a permutation of another string then they must have one common metric. What is that?
 * Hint 5: Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
 * Hint 6: What about hash table? An array of size 26?
 * 
 */

class Solution {
public:
    bool check(int i , int j , unordered_map<char,int>mp,string& s2){
        unordered_map<char,int> freq;

        for(int k = i ; k <= j ; k++){
            freq[s2[k]]++;
        }

        return freq == mp;
    }
    
    bool checkInclusion(string s1, string s2) {
        //1.we have to fix the window length
        //2.we have to compute the freq map of s1
        //and for every window we should check if the freq map is matching with the freq map
        //of the s1

        unordered_map<char,int> mp;

        for(int i = 0 ; i < s1.length() ; i++){
            mp[s1[i]]++;
        }

        int i = 0;
        int j = s1.length() - 1;

        while(j < s2.length()){
           
           if(check(i,j,mp,s2)){
            return true;
           }
           else{
             i++;
             j++;
           }
        }
        return false;
    }
};