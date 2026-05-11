/*
 * Problem: Valid Parentheses
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-parentheses/
 * Language: cpp
 * Topics: String, Stack
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a string s containing just the characters &#39;(&#39; , &#39;)&#39; , &#39;{&#39; , &#39;}&#39; , &#39;[&#39; and &#39;]&#39; , determine if the input string is valid.
 * An input string is valid if:
 * • Open brackets must be closed by the same type of brackets.
 * • Open brackets must be closed in the correct order.
 * • Every close bracket has a corresponding open bracket of the same type.
 * Example 1:
 * Input: s = &quot;()&quot;
 * Output: true
 * Example 2:
 * Input: s = &quot;()[]{}&quot;
 * Output: true
 * Example 3:
 * Input: s = &quot;(]&quot;
 * Output: false
 * Example 4:
 * Input: s = &quot;([])&quot;
 * Output: true
 * Example 5:
 * Input: s = &quot;([)]&quot;
 * Output: false
 * Constraints:
 * • 1 <= s.length <= 10 4
 * • s consists of parentheses only &#39;()[]{}&#39; .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use a stack of characters.
 * Hint 2: When you encounter an opening bracket, push it to the top of the stack.
 * Hint 3: When you encounter a closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.
 * 
 */

class Solution {
public:
    bool is_opening(char a,char b){
        if(a == '[' && b == ']' || a == '(' && b == ')' || a == '{' && b == '}'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>st;

        int n = s.length();
        int i = 0 ;
        while(i < n){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(!is_opening(st.top(),s[i])){
                   return false;
                }
                
                st.pop();
            }
            i++;
        }
        return st.empty();
    }
};