/*
 * Problem: A. Football
 * Contest: 96 | Problem A
 * Link: https://codeforces.com/contest/96/problem/A
 *
 * --- Input ---
 * The first input line contains a non-empty string consisting of characters &quot;0&quot; and &quot;1&quot;, which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field. Output Print &quot;YES&quot; if the situation is dangerous. Otherwise, print &quot;NO&quot;. Examples Input 001001 Output NO Input 1000000001 Output YES
 *
 * --- Output ---
 * Print &quot;YES&quot; if the situation is dangerous. Otherwise, print &quot;NO&quot;. Examples Input 001001 Output NO Input 1000000001 Output YES
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool is_dangerous(string s) {
    int count = 1;   // start from 1

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count == 7)
                return true;
        } else {
            count = 1;
        }
    }

    return false;
}

void solve() {
    string s;
    cin >> s;

    if (is_dangerous(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}
