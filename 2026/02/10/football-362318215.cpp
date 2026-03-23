/*
 * Problem: A. Football
 * Contest: 96/A | Link: https://codeforces.com/contest/96/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.
 *
 * ── Input ────────────────────────────────────────────────
 * The first input line contains a non-empty string consisting of characters &quot;0&quot; and &quot;1&quot;, which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.
 *
 * ── Output ───────────────────────────────────────────────
 * Print &quot;YES&quot; if the situation is dangerous. Otherwise, print &quot;NO&quot;.
 *
 * ── Example Input ────────────────────────────────────────
 * 001001 | 1000000001
 *
 * ── Example Output ───────────────────────────────────────
 * NO | YES
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
