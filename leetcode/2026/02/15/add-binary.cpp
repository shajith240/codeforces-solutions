/*
 * Problem: Add Binary
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/add-binary/
 * Language: cpp
 * Topics: Math, String, Bit Manipulation, Simulation
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two binary strings a and b , return their sum as a binary string .
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * Constraints:
 * • 1 <= a.length, b.length <= 10 4
 * • a and b consist only of &#39;0&#39; or &#39;1&#39; characters.
 * • Each string does not contain leading zeros except for the zero itself.
 * 
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1;
        int n = b.length() - 1;
        
        string result = "";
        int sum = 0;
        int carry = 0;
        while(n >= 0 || m >= 0){
            sum = carry;


            if(m >= 0){
                sum += a[m] - '0';
                m--;
            }
            if(n >= 0){
                sum += b[n] - '0';
                n--;
            }

            result.push_back((sum % 2) == 0 ? '0' : '1');

            carry = sum / 2;
        }

        if(carry){
            result.push_back('1');
        }

        reverse(result.begin(),result.end());

        return result;
    }
};