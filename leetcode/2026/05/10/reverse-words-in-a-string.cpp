/*
 * Problem: Reverse Words in a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 * Language: cpp
 * Topics: Two Pointers, String
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an input string s , reverse the order of the words .
 * A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 * Return a string of the words in reverse order concatenated by a single space.
 * Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
 * Example 1:
 * Input: s = &quot;the sky is blue&quot;
 * Output: &quot;blue is sky the&quot;
 * Example 2:
 * Input: s = &quot; hello world &quot;
 * Output: &quot;world hello&quot;
 * Explanation: Your reversed string should not contain leading or trailing spaces.
 * Example 3:
 * Input: s = &quot;a good example&quot;
 * Output: &quot;example good a&quot;
 * Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 * Constraints:
 * • 1 <= s.length <= 10 4
 * • s contains English letters (upper-case and lower-case), digits, and spaces &#39; &#39; .
 * • There is at least one word in s .
 * Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
 * 
 */

class Solution {
public:
    string reverseWords(string s) {
        //what is the process actually
        //1.reverse the given string

        reverse(s.begin(),s.end());

        int i = 0;
        int l = 0,r = 0;
        
        int n = s.length();
        while(i < n){
           
           while(i < n && s[i] != ' '){
               s[r++] = s[i++];
           }

           if(l < r){
             reverse(s.begin() + l , s.begin() + r);
             s[r] = ' ';
             r++;
             l = r;
           }
           i++;
        }

        s = s.substr(0,r - 1);

        return s;
    }
};