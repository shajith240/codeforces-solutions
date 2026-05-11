/*
 * Problem: Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Language: cpp
 * Topics: Array, Math, Stack
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation .
 * Evaluate the expression. Return an integer that represents the value of the expression .
 * Note that:
 * • The valid operators are &#39;+&#39; , &#39;-&#39; , &#39;*&#39; , and &#39;/&#39; .
 * • Each operand may be an integer or another expression.
 * • The division between two integers always truncates toward zero .
 * • There will not be any division by zero.
 * • The input represents a valid arithmetic expression in a reverse polish notation.
 * • The answer and all the intermediate calculations can be represented in a 32-bit integer.
 * Example 1:
 * Input: tokens = [&quot;2&quot;,&quot;1&quot;,&quot;+&quot;,&quot;3&quot;,&quot;*&quot;]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * Example 2:
 * Input: tokens = [&quot;4&quot;,&quot;13&quot;,&quot;5&quot;,&quot;/&quot;,&quot;+&quot;]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * Example 3:
 * Input: tokens = [&quot;10&quot;,&quot;6&quot;,&quot;9&quot;,&quot;3&quot;,&quot;+&quot;,&quot;-11&quot;,&quot;*&quot;,&quot;/&quot;,&quot;*&quot;,&quot;17&quot;,&quot;+&quot;,&quot;5&quot;,&quot;+&quot;]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * Constraints:
 * • 1 <= tokens.length <= 10 4
 * • tokens[i] is either an operator: &quot;+&quot; , &quot;-&quot; , &quot;*&quot; , or &quot;/&quot; , or an integer in the range [-200, 200] .
 * 
 */

class Solution {
public:

    bool is_operator(char c) {

        if(c == '+' || c == '*' || c == '-' || c == '/') {
            return true;
        }

        return false;
    }

    int do_operation(int first, int second, char c) {

        switch(c) {

            case '*':
                return first * second;

            case '+':
                return first + second;

            case '-':
                return first - second;

            case '/':
                return first / second;
        }

        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        int n = tokens.size();

        int i = 0;

        while(i < n) {

            if(!is_operator(tokens[i][0]) || tokens[i].size() > 1) {

                st.push(stoi(tokens[i]));
            }

            else {

                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                int ans = do_operation(first, second, tokens[i][0]);

                st.push(ans);
            }

            i++;
        }

        return st.top();
    }
};