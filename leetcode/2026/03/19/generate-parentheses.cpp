/*
 * Problem: Generate Parentheses
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/generate-parentheses/
 * Language: cpp
 * Topics: String, Dynamic Programming, Backtracking
 * 
 * ── Problem ────────────────────────────────────────────
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses .
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * Constraints:
 * • 1 <= n <= 8
 * 
 */

class Solution {
public:

    vector<string> result;
    
    bool isvalid(string curr){
        int count = 0;

        for(char &ch : curr){
            if(ch == '('){
                count++;
            }
            else
                count--;
            
            if(count < 0){
                return false;
            }
        }
        return count == 0;
    }

    void solve(string& curr , int n){
        if(curr.length() == 2 * n){
            if(isvalid(curr)){
                result.push_back(curr);
            }
            return;
        }


        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();


        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n);
        return result;
    }
};