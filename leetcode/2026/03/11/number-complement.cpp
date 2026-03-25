/*
 * Problem: Number Complement
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/number-complement/
 * Language: cpp
 * Topics: Bit Manipulation
 * 
 * ── Problem ────────────────────────────────────────────
 * The complement of an integer is the integer you get when you flip all the 0 &#39;s to 1 &#39;s and all the 1 &#39;s to 0 &#39;s in its binary representation.
 * • For example, The integer 5 is &quot;101&quot; in binary and its complement is &quot;010&quot; which is the integer 2 .
 * Given an integer num , return its complement .
 * Example 1:
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * Example 2:
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 * Constraints:
 * • 1 <= num < 2 31
 * Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
 * 
 */

class Solution {
public:
    string DecimalToBinary(int n){
        if(n == 0){
            return "0";
        }
        int digit = 0;
        string rem = "";
        while(n > 0){
           digit = n % 2;
           if(digit == 1){
             rem += '1';
           }
           else{
            rem+= '0';
           }
           n = n /2;
        }

        reverse(rem.begin(),rem.end());
        return rem;
    }


    int BinaryToDecimal(string s){
        int sum = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            sum += (s[n - i - 1] - '0') * (1 << i);
        }
        return sum;
    }

    int findComplement(int num) {
        string ans = DecimalToBinary(num);

        for(int i = 0 ; i < ans.length() ; i++){
            if(ans[i] == '1'){
                ans[i] = '0';
            }
            else{
                ans[i] = '1';
            }
        }
       
       return BinaryToDecimal(ans);
    }
};