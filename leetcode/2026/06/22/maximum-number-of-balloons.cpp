/*
 * Problem: Maximum Number of Balloons
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-number-of-balloons/
 * Language: cpp
 * Topics: Hash Table, String, Counting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string text , you want to use the characters of text to form as many instances of the word &quot;balloon&quot; as possible.
 * You can use each character in text at most once . Return the maximum number of instances that can be formed.
 * Example 1:
 * Input: text = &quot;nlaebolko&quot;
 * Output: 1
 * Example 2:
 * Input: text = &quot;loonbalxballpoon&quot;
 * Output: 2
 * Example 3:
 * Input: text = &quot;leetcode&quot;
 * Output: 0
 * Constraints:
 * • 1 <= text.length <= 10 4
 * • text consists of lower case English letters only.
 * Note: This question is the same as 2287: Rearrange Characters to Make Target String.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Count the frequency of letters in the given string.
 * Hint 2: Find the letter than can make the minimum number of instances of the word "balloon".
 * 
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> mp;

        for(char &ch : text){
            mp[ch]++;
        }

        int count = 0;
        while(mp['b'] >= 1 && mp['a'] >= 1 && mp['l'] >= 2 && mp['o'] >= 2 && mp['n'] >= 1){
            mp['b']--;
            mp['a']--;
            mp['l'] = mp['l'] - 2;
            mp['o'] = mp['o'] - 2;
            mp['n']--;
            count++;
        }

        return count;
    }
};