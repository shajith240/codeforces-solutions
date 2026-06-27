/*
 * Problem: C. Nim Game Is XOR Game
 * Contest: 2240/C | Link: https://codeforces.com/contest/2240/problem/C
 *
 * ── Problem ──────────────────────────────────────────────
 * Hacks are disabled in this problem.
 * Alice and Bob are playing a game with an array a consisting of n non-negative integers. Alice goes first.
 * In each turn, the current player must choose an array of n non-negative integers b = [b_1, b_2, ..., b_n] that satisfies the following conditions:
 * 
 * • 0 ≤ b_i ≤ a_i for all 1 ≤ i ≤ n;
 * • _(i=1)^n b_i 0 (i.e. the array b does not consist entirely of zeros);
 * • b_1 b_2 ... b_n = 0, where $denotes the bitwise XOR operation . After choosing the arrayb, the player updates the arrayaby performinga_i ≤ftarrow a_i - b_ifor all1 ≤ i ≤ n.
 * The player who cannot perform such an operation loses the game.
 * Determine the number of valid choices for the arraybthat Alice can make on her first turn to guarantee a win, assuming both players play optimally. Since this number may be large, output the answer modulo998\,244\,353$.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
 * The first line of each test case contains a single integer n (1 ≤ n ≤ 10^6) — the length of the array a.
 * The second line of each test case contains n integers a_1, a_2, ..., a_n (1 ≤ a_i 2^(30)) — the contents of the array a
 * It is guaranteed that the sum of n over all test cases does not exceed 10^6.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output the number of valid choices for the array b that Alice can make on her first turn to guarantee a win modulo 998\,244\,353.
 *
 * ── Example Input ────────────────────────────────────────
 * 5
 * 1
 * 1
 * 2
 * 1 2
 * 5
 * 1 4 5 2 6
 * 1
 * 1073741823
 * 3
 * 1 2 3
 *
 * ── Example Output ───────────────────────────────────────
 * 0
 * 1
 * 3
 * 0
 * 1
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, Alice must choose an array b of length 1. The conditions require b_1 ≤ a_1, b_1 0, and b_1 = 0. It is impossible to satisfy b_1 0 and b_1 = 0 simultaneously. Thus, Alice has no valid moves and loses immediately. The answer is 0.
 * In the second test case, a = [1, 2]. Alice must choose b = [b_1, b_2]. The condition b_1 b_2 = 0 implies that b_1 = b_2. Since 0 ≤ b_1 ≤ 1 and 0 ≤ b_2 ≤ 2, and the array b cannot consist entirely of zeros, the only valid choice is b = [1, 1]. If Alice chooses b = [1, 1], the array updates to a = [1-1, 2-1] = [0, 1]. Now it is Bob's turn. Similar to Alice's situation, Bob must choose b' such that b'_1 = b'_2. Since a_1 = 0, he is forced to pick b'_1 = 0, which means b'_2 = 0. Since a valid move must have b'_i 0, Bob has no valid moves and loses. Therefore, b = [1, 1] is a winning move for Alice, and the answer is 1.
 *
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    int s = 0;
    int non_zeros = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s ^= a[i]; // Calculate the total XOR sum
        if (a[i] > 0) {
            non_zeros++;
        }
    }
    
    // If the array already has 1 or 0 non-zero elements, 
    // Alice has 0 valid moves and loses immediately.
    if (non_zeros <= 1) {
        cout << 0 << "\n";
        return;
    }
    
    int valid_moves = 0;
    
    // Option 1: We wipe out the entire array leaving 0 non-zeros.
    // This is only mathematically valid if the starting XOR sum is exactly 0.
    if (s == 0) {
        valid_moves++;
    }
    
    // Option 2: We wipe out everything EXCEPT one element.
    // We check every index to see if it can legally be the surviving element.
    for (int i = 0; i < n; i++) {
        if ((s ^ a[i]) < a[i]) {
            valid_moves++;
        }
    }
    
    
    cout << valid_moves % 998244353 << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}