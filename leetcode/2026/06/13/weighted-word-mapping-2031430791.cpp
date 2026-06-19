/*
 * Problem: Weighted Word Mapping
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/weighted-word-mapping/
 * Language: cpp
 * Topics: Array, String, Simulation
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an array of strings words , where each string represents a word containing lowercase English letters.
 * You are also given an integer array weights of length 26, where weights[i] represents the weight of the i th lowercase English letter.
 * The weight of a word is defined as the sum of the weights of its characters.
 * For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order ( 0 -> &#39;z&#39;, 1 -> &#39;y&#39;, ..., 25 -> &#39;a&#39; ).
 * Return a string formed by concatenating the mapped characters for all words in order.
 * Example 1:
 * Input: words = [&quot;abcd&quot;,&quot;def&quot;,&quot;xyz&quot;], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
 * Output: &quot;rij&quot;
 * Explanation:
 * • The weight of &quot;abcd&quot; is 5 + 3 + 12 + 14 = 34 . The result modulo 26 is 34 % 26 = 8 , which maps to &#39;r&#39; .
 * • The weight of &quot;def&quot; is 14 + 1 + 2 = 17 . The result modulo 26 is 17 % 26 = 17 , which maps to &#39;i&#39; .
 * • The weight of &quot;xyz&quot; is 7 + 7 + 2 = 16 . The result modulo 26 is 16 % 26 = 16 , which maps to &#39;j&#39; .
 * Thus, the string formed by concatenating the mapped characters is &quot;rij&quot; .
 * Example 2:
 * Input: words = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;], weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
 * Output: &quot;yyy&quot;
 * Explanation:
 * Each word has weight 1. The result modulo 26 is 1 % 26 = 1 , which maps to &#39;y&#39; .
 * Thus, the string formed by concatenating the mapped characters is &quot;yyy&quot; .
 * Example 3:
 * Input: words = [&quot;abcd&quot;], weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]
 * Output: &quot;g&quot;
 * Explanation:​​​​​​​
 * The weight of &quot;abcd&quot; is 7 + 5 + 3 + 4 = 19 . The result modulo 26 is 19 % 26 = 19 , which maps to &#39;g&#39; .
 * Thus, the string formed by concatenating the mapped characters is &quot;g&quot; .
 * Constraints:
 * • 1 <= words.length <= 100
 * • 1 <= words[i].length <= 10
 * • weights.length == 26
 * • 1 <= weights[i] <= 100
 * • words[i] consists of lowercase English letters.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: For each word, sum character weights using weights[c - 'a']
 * Hint 2: Take the sum modulo 26
 * Hint 3: Map the value to a character using reverse order: char = 'z' - value
 * Hint 4: Append all mapped characters in order to form the result string
 * 
 */

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string result = "";
        for(int i = 0 ; i < n ; i++){
            string s = words[i];
            int sum = 0;
            for(int j = 0 ; j < s.length() ; j++){
                int index = (int)s[j] - 97;
                sum += weights[index];
            }

            int index = 26 - sum % 26 ;

            char c = (char)index + 96;
            result += c;
        }
        return result;
    }

    //what are the input's here 
    //1.they will give words and weights(fixed size)
    //for every work we have to calculate the weight of by using the weights array
    //and take modulo and save it in a alphabetical map
};