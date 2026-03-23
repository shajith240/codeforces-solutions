/*
 * Problem: B. Array
 * Contest: 2209/B | Link: https://codeforces.com/contest/2209/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * You are given an integer array $$$a$$$ of length $$$n$$$. For each index $$$i$$$, find the maximum number of indices $$$j$$$ such that $$$j \gt i$$$ and $$$|a_i - k| \gt |a_j - k|$$$, over all possible integer values of $$$k$$$.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows. The first line of each test case contains an integer $$$n$$$ ($$$1 \le n \le 5000$$$). The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$-10^9 \le a_i \le 10^9$$$). It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$5000$$$.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output $$$n$$$ integers denoting the answer.
 *
 * ── Example Input ────────────────────────────────────────
 * 6 1 1092 2 105 -105 5 1 2 93 84 2 7 2 9 38 4 7 1 6 10 1 9 20 9 829 3 87 1 283 7 11 9 18 29817 283 3 3928 5726 1942 1000000000 -1000000000 19
 *
 * ── Example Output ───────────────────────────────────────
 * 0 1 0 4 2 2 1 0 5 4 4 2 2 1 0 8 4 4 3 5 3 2 2 1 0 8 7 7 4 5 3 3 2 2 1 0
 *
 * ── Notes ────────────────────────────────────────────────
 * In the second test, the answers are: For $$$i=1$$$, you can choose $$$k=-195$$$, then $$$j=2$$$. For $$$i=2$$$, you can choose $$$k=5$$$, there exists no index $$$j \gt i$$$. In the third test, the answers are: For $$$i=1$$$, you can choose $$$k=195$$$, then $$$j=2,3,4,5$$$. For $$$i=2$$$, you can choose $$$k=78$$$, then $$$j=3,4$$$. For $$$i=3$$$, you can choose $$$k=15$$$, then $$$j=4,5$$$. For $$$i=4$$$, you can choose $$$k=15$$$, then $$$j=5$$$. For $$$i=5$$$, you can choose $$$k=998\,244\,353$$$, there exists no index $$$j \gt i$$$.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        for (int i = 0; i < n; i++) {
            int less_count = 0, greater_count = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) less_count++;
                else if (a[j] > a[i]) greater_count++;
            }
            cout << max(less_count, greater_count);
            if (i < n - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
