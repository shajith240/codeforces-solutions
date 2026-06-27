/*
 * Problem: C. Binary Strings are Fun
 * Contest: 1762/C | Link: https://codeforces.com/contest/1762/problem/C
 *
 * ── Problem ──────────────────────────────────────────────
 * A binary string^ b of odd length m is good if b_i is the median^ of b[1,i]^ for all odd indices i (1 ≤q i ≤q m).
 * For a binary string a of length k, a binary string b of length 2k-1 is an extension of a if b_(2i-1)=a_i for all i such that 1 ≤q i ≤q k. For example, 1 0 0 1 0 1 1 and 1 1 0 1 0 0 1 are extensions of the string 1001 . String x= 1011011 is not an extension of string y= 1001 because x_3 ≠ y_2. Note that there are 2^(k-1) different extensions of a.
 * You are given a binary string s of length n. Find the sum of the number of good extensions over all prefixes of s. In other words, find _(i=1)^(n) f(s[1,i]), where f(x) gives number of good extensions of string x. Since the answer can be quite large, you only need to find it modulo 998\,244\,353.
 * ^ A binary string is a string whose elements are either 0 or 1.
 * ^ For a binary string a of length 2m-1, the median of a is the (unique) element that occurs at least m times in a.
 * ^ a[l,r] denotes the string of length r-l+1 which is formed by the concatenation of a_l,a_(l+1),...,a_r in that order.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
 * The first line of each test case contains a single integer n (1 ≤ n ≤ 2 · 10^5), where n is the length of the binary string s.
 * The second line of each test case contains the binary string s of length n.
 * It is guaranteed that the sum of n over all test cases does not exceed 2 · 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, print the answer modulo 998\,244\,353.
 *
 * ── Example Input ────────────────────────────────────────
 * 6
 * 1
 * 1
 * 1
 * 0
 * 2
 * 11
 * 3
 * 010
 * 9
 * 101101111
 * 37
 * 1011011111011010000011011111111011111
 *
 * ── Example Output ───────────────────────────────────────
 * 1
 * 1
 * 3
 * 3
 * 21
 * 365
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first and second test cases, f(s[1,1])=1.
 * In the third test case, the answer is f(s[1,1])+f(s[1,2])=1+2=3.
 * In the fourth test case, the answer is f(s[1,1])+f(s[1,2])+f(s[1,3])=1+1+1=3.
 * f(11)=2 because two good extensions are possible: 101 and 111 .
 * f(01)=1 because only one good extension is possible: 011 .
 *
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Precompute powers of 2 to keep it O(N)
    vector<long long> p2(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        p2[i] = (p2[i-1] * 2) % MOD;
    }
    
    long long ans = 0;
    int current_len = 0;
    
    for(int i = 0; i < n; i++) {
        // If the character matches the previous one, extend the block length
        if (i == 0 || s[i] == s[i-1]) {
            current_len++;
        } else {
            // Otherwise, reset the block length
            current_len = 1;
        }
        
        // Add 2^(current_len - 1) to the answer
        ans = (ans + p2[current_len - 1]) % MOD;
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}