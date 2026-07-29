/*
 * Problem: A. Divide and Conquer
 * Contest: 2241/A | Link: https://codeforces.com/contest/2241/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * You are given two positive integers x and y.
 * You are allowed to perform the following operation any number of times (possibly zero):
 * 
 * • Choose any positive integer z such that z divides x;
 * • Set x := (x)/(z). Determine whether you can make x exactly equal to y using this operation.
 *
 * ── Input ────────────────────────────────────────────────
 * The first line of the input contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases. The description of each test case follows.
 * The only line of each test case contains two space-separated integers x and y (1 ≤ x, y ≤ 100).
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, print &quot; YES &quot; if you can make x exactly equal to y and &quot; NO &quot; otherwise.
 * You can output &quot; YES &quot; and &quot; NO &quot; in any case (for example, strings &quot; yEs &quot;, &quot; yes &quot; and &quot; Yes &quot; will be recognized as a positive response).
 *
 * ── Example Input ────────────────────────────────────────
 * 3
 * 12 2
 * 6 7
 * 99 79
 *
 * ── Example Output ───────────────────────────────────────
 * YES
 * NO
 * NO
 *
 * ── Notes ────────────────────────────────────────────────
 * For the first test case,
 * 
 * • Choosing z = 2 makes x = (12)/(2) = 6
 * • Choosing z = 3 makes x = (6)/(3) = 2 Thus, we can make x = y. Hence, output YES.
 * For the second test case, it can be shown that it is impossible to make x equal to y.
 *
 */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    
    if (x % y == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}