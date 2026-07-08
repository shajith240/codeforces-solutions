/*
 * Problem: Concatenate Non-Zero Digits and Multiply by Sum II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/
 * Language: cpp
 * Topics: Math, String, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a string s of length m consisting of digits. You are also given a 2D integer array queries , where queries[i] = [l i , r i ] .
 * For each queries[i] , extract the substring s[l i ..r i ] . Then, perform the following:
 * • Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0 .
 * • Let sum be the sum of digits in x . The answer is x * sum .
 * Return an array of integers answer where answer[i] is the answer to the i th query.
 * Since the answers may be very large, return them modulo 10 9 + 7 .
 * Example 1:
 * Input: s = &quot;10203004&quot;, queries = [[0,7],[1,3],[4,6]]
 * Output: [12340, 4, 9]
 * Explanation:
 * • s[0..7] = &quot;10203004&quot;
 * • x = 1234
 * • sum = 1 + 2 + 3 + 4 = 10
 * • Therefore, answer is 1234 * 10 = 12340 .
 * • s[1..3] = &quot;020&quot;
 * • x = 2
 * • sum = 2
 * • Therefore, the answer is 2 * 2 = 4 .
 * • s[4..6] = &quot;300&quot;
 * • x = 3
 * • sum = 3
 * • Therefore, the answer is 3 * 3 = 9 .
 * Example 2:
 * Input: s = &quot;1000&quot;, queries = [[0,3],[1,1]]
 * Output: [1, 0]
 * Explanation:
 * • s[0..3] = &quot;1000&quot;
 * • x = 1
 * • sum = 1
 * • Therefore, the answer is 1 * 1 = 1 .
 * • s[1..1] = &quot;0&quot;
 * • x = 0
 * • sum = 0
 * • Therefore, the answer is 0 * 0 = 0 .
 * Example 3:
 * Input: s = &quot;9876543210&quot;, queries = [[0,9]]
 * Output: [444444137]
 * Explanation:
 * • s[0..9] = &quot;9876543210&quot;
 * • x = 987654321
 * • sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
 * • Therefore, the answer is 987654321 * 45 = 44444444445 .
 * • We return 44444444445 modulo (10 9 + 7) = 444444137 .
 * Constraints:
 * • 1 <= m == s.length <= 10 5
 * • s consists of digits only.
 * • 1 <= queries.length <= 10 5
 * • queries[i] = [l i , r i ]
 * • 0 <= l i <= r i < m
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Track only nonzero digits: store their values and positions and keep a prefix sum for digit sums.
 * Hint 2: Also build prefix concatenation values P , pow10 , and set mod = 10 9 +7 so any compressed substring number is obtainable from prefixes.
 * Hint 3: Map each query [l, r] to the compressed list using precomputed mapping arrays (first nonzero at or after i
 * Hint 4: If the mapped range is empty return 0 ; otherwise get x from P , get sum from the digit-prefix, and return (x * sum) % mod .
 * 
 */

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // what is the thought process in this is like
        // we build 2 diffrent array's to fetch the info and calculate the
        // things we should be able to get he x * sum by the end so we will
        // store the cummulative sum's in a array of length of the s in the same
        // way we store the number of not zero digits so we can compute the k
        // here the k is used for to build the number that is used to do the
        // subtraction of the number we build so far

        // if we need the sum or string from [l,r] we just do like
        // sumofthestring[r] - sumofthestring[l-1] for x we do the same but we
        // need to cut off some digits from it so we use number * 10^k that k
        // wich we will get from the formula again like numberofnozeros[r] -
        // numberofnonzeros[l-1]

        int n = s.length();

        vector<int> nonZeroCount(n, 0); // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(
            n, 0); // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0); // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);    // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        numberUpTo[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            ll x =
                (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) %
                MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};