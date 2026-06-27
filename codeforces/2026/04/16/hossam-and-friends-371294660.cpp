/*
 * Problem: B. Hossam and Friends
 * Contest: 1771/B | Link: https://codeforces.com/contest/1771/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * Hossam makes a big party, and he will invite his friends to the party.
 * He has n friends numbered from 1 to n. They will be arranged in a queue as follows: 1, 2, 3, ..., n.
 * Hossam has a list of m pairs of his friends that don't know each other. Any pair not present in this list are friends.
 * A subsegment of the queue starting from the friend a and ending at the friend b is [a, a + 1, a + 2, ..., b]. A subsegment of the queue is called good when all pairs of that segment are friends.
 * Hossam wants to know how many pairs (a, b) there are (1 ≤ a ≤ b ≤ n), such that the subsegment starting from the friend a and ending at the friend b is good.
 *
 * ── Input ────────────────────────────────────────────────
 * The input consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 2 · 10^4), the number of test cases. Description of the test cases follows.
 * The first line of each test case contains two integer numbers n and m (2 ≤ n ≤ 10^5, 0 ≤ m ≤ 10^5) representing the number of friends and the number of pairs, respectively.
 * The i-th of the next m lines contains two integers x_i and y_i (1 ≤ x_i, y_i≤ n, x_i ≠ y_i) representing a pair of Hossam's friends that don't know each other.
 * Note that pairs can be repeated.
 * It is guaranteed that the sum of n over all test cases does not exceed 10^5, and the sum of m over all test cases does not exceed 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case print an integer — the number of good subsegments.
 *
 * ── Example Input ────────────────────────────────────────
 * 2
 * 3 2
 * 1 3
 * 2 3
 * 4 2
 * 1 2
 * 2 3
 *
 * ── Example Output ───────────────────────────────────────
 * 4
 * 5
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first example, the answer is 4.
 * The good subsegments are:
 * [1]
 * [2]
 * [3]
 * [1, 2]
 * In the second example, the answer is 5.
 * The good subsegments are:
 * [1]
 * [2]
 * [3]
 * [4]
 * [3, 4]
 *
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // limit[i] will store the furthest right we can go starting from i
    vector<int> limit(n + 1, n);

    // Process the non-friend pairs
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // Make sure x is the smaller index and y is the larger
        int x = min(u, v);
        int y = max(u, v);
        
        // A segment starting at x cannot reach y
        limit[x] = min(limit[x], y - 1);
    }

    // Ripple effect: propagate the limits from right to left
    for (int i = n - 1; i >= 1; i--) {
        limit[i] = min(limit[i], limit[i + 1]);
    }

    // Count total valid segments
    long long total_good_segments = 0; // Use long long to avoid overflow!
    for (int i = 1; i <= n; i++) {
        total_good_segments += (limit[i] - i + 1);
    }

    cout << total_good_segments << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}