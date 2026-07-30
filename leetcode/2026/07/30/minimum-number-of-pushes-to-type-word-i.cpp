/*
 * Problem: Minimum Number of Pushes to Type Word I
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 * Language: cpp
 * Topics: Math, String, Greedy
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a string word containing distinct lowercase English letters.
 * Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;] , we need to push the key one time to type &quot;a&quot; , two times to type &quot;b&quot; , and three times to type &quot;c&quot; .
 * It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word .
 * Return the minimum number of pushes needed to type word after remapping the keys .
 * An example mapping of letters to keys on a telephone keypad is given below. Note that 1 , * , # , and 0 do not map to any letters.
 * Example 1:
 * Input: word = &quot;abcde&quot;
 * Output: 5
 * Explanation: The remapped keypad given in the image provides the minimum cost.
 * &quot;a&quot; -> one push on key 2
 * &quot;b&quot; -> one push on key 3
 * &quot;c&quot; -> one push on key 4
 * &quot;d&quot; -> one push on key 5
 * &quot;e&quot; -> one push on key 6
 * Total cost is 1 + 1 + 1 + 1 + 1 = 5.
 * It can be shown that no other mapping can provide a lower cost.
 * Example 2:
 * Input: word = &quot;xycdefghij&quot;
 * Output: 12
 * Explanation: The remapped keypad given in the image provides the minimum cost.
 * &quot;x&quot; -> one push on key 2
 * &quot;y&quot; -> two pushes on key 2
 * &quot;c&quot; -> one push on key 3
 * &quot;d&quot; -> two pushes on key 3
 * &quot;e&quot; -> one push on key 4
 * &quot;f&quot; -> one push on key 5
 * &quot;g&quot; -> one push on key 6
 * &quot;h&quot; -> one push on key 7
 * &quot;i&quot; -> one push on key 8
 * &quot;j&quot; -> one push on key 9
 * Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
 * It can be shown that no other mapping can provide a lower cost.
 * Constraints:
 * • 1 <= word.length <= 26
 * • word consists of lowercase English letters.
 * • All letters in word are distinct.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: We have 8 keys in total. We can type 8 characters with one push each, 8 different characters with two pushes each, and so on.
 * Hint 2: The optimal way is to map letters to keys evenly.
 * 
 */

class Solution {
public:
    int minimumPushes(string word) {
        //first we will just save the press in a 26 sized array and then we just return the sum accordingly
        int ans = 0;
        for(int i = 0 ; i < word.length() ; i++){
            ans += (i / 8) + 1;
        }

        return ans;
    }
};