/*
 * Problem: Reverse Vowels of a String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Language: cpp
 * Topics: Two Pointers, String
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string s , reverse only all the vowels in the string and return it.
 * The vowels are &#39;a&#39; , &#39;e&#39; , &#39;i&#39; , &#39;o&#39; , and &#39;u&#39; , and they can appear in both lower and upper cases, more than once.
 * Example 1:
 * Input: s = &quot;IceCreAm&quot;
 * Output: &quot;AceCreIm&quot;
 * Explanation:
 * The vowels in s are [&#39;I&#39;, &#39;e&#39;, &#39;e&#39;, &#39;A&#39;] . On reversing the vowels, s becomes &quot;AceCreIm&quot; .
 * Example 2:
 * Input: s = &quot;leetcode&quot;
 * Output: &quot;leotcede&quot;
 * Constraints:
 * • 1 <= s.length <= 3 * 10 5
 * • s consist of printable ASCII characters.
 * 
 */

class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
           }

           return false;
    }

    string reverseVowels(string s) {
        int i = 0 ;
        int j = s.length() - 1;

        while(j >= i){
            if(isvowel(s[i]) && isvowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isvowel(s[i])){
                i++;
            }
            else if(!isvowel(s[j])){
                j--;
            }
        }

        return s;
    }
}; 