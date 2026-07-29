/*
 * Problem: C. Doremy's City Construction
 * Contest: 1764/C | Link: https://codeforces.com/contest/1764/problem/C
 *
 * ── Problem ──────────────────────────────────────────────
 * Doremy's new city is under construction! The city can be regarded as a simple undirected graph with n vertices. The i-th vertex has altitude a_i. Now Doremy is deciding which pairs of vertices should be connected with edges.
 * Due to economic reasons, there should be no self-loops or multiple edges in the graph.
 * Due to safety reasons, there should not be pairwise distinct vertices u, v, and w such that a_u ≤q a_v ≤q a_w and the edges (u,v) and (v,w) exist.
 * Under these constraints, Doremy would like to know the maximum possible number of edges in the graph. Can you help her?
 * Note that the constructed graph is allowed to be disconnected.
 *
 * ── Input ────────────────────────────────────────────────
 * The input consists of multiple test cases. The first line contains a single integer t (1≤ t≤ 10^4) — the number of test cases. The description of the test cases follows.
 * The first line of each test case contains a single integer n (2 ≤ n ≤ 2· 10^5) — the number of vertices.
 * The second line of each test case contains n integers a_1, a_2, ..., a_n (1≤ a_i≤ 10^6) — the altitudes of each vertex.
 * It is guaranteed that the sum of n over all test cases does not exceed 2 · 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output the maximum possible number of edges in the graph.
 *
 * ── Example Input ────────────────────────────────────────
 * 4
 * 4
 * 2 2 3 1
 * 6
 * 5 2 3 1 5 2
 * 12
 * 7 2 4 9 1 4 6 3 7 4 2 3
 * 4
 * 1000000 1000000 1000000 1000000
 *
 * ── Example Output ───────────────────────────────────────
 * 3
 * 9
 * 35
 * 2
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, there can only be at most 3 edges in the graph. A possible construction is to connect (1,3), (2,3), (3,4). In the picture below the red number above node i is a_i.
 * 
 * The following list shows all such u, v, w that the edges (u,v) and (v,w) exist.
 * 
 * • u=1, v=3, w=2;
 * • u=1, v=3, w=4;
 * • u=2, v=3, w=1;
 * • u=2, v=3, w=4;
 * • u=4, v=3, w=1;
 * • u=4, v=3, w=2. Another possible construction is to connect (1,4), (2,4), (3,4).
 * 
 * An unacceptable construction is to connect (1,3), (2,3), (2,4), (3,4). Because when u=4, v=2, w=3, a_u≤ a_v ≤ a_w holds, and the respective edges exist.
 *
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Step 1: Sort the altitudes
    sort(a.begin(), a.end());
    
    // Step 2: Handle the edge case where all elements are identical
    if (a[0] == a[n - 1]) {
        cout << n / 2 << "\n";
        return;
    }
    
    // Step 3: Find the optimal bipartite split
    long long max_edges = 0;
    
    for (int i = 0; i < n - 1; i++) {
        // We can only split if the left max is strictly less than the right min
        if (a[i] < a[i + 1]) {
            long long left_count = i + 1;
            long long right_count = n - (i + 1);
            long long current_edges = left_count * right_count;
            
            max_edges = max(max_edges, current_edges);
        }
    }
    
    cout << max_edges << "\n";
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