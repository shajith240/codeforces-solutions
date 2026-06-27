/*
 * Problem: A. Another Popcount Problem
 * Contest: 2240/A | Link: https://codeforces.com/contest/2240/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * Hacks are disabled in this problem.
 * You are given two integers n and k.
 * Your task is to construct a sequence a consisting of k non-negative integers a_1, a_2, ..., a_k such that:
 * 
 * • _(i=1)^(k) a_i ≤ n
 * • The total number of set bits, i.e., _(i=1)^(k) popcount(a_i), is as large as possible. You only need to output the maximum possible value of _(i=1)^(k) popcount(a_i).
 * Here, popcount(x) denotes the number of 1 bits in the binary representation of x. For example, popcount(6) = popcount((110)_2) = 2, and popcount(0) = 0.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^3). The description of the test cases follows.
 * Each of the next t lines contains two integers n and k (1 ≤ n, k ≤ 10^6) — the maximum allowed sum of the sequence and the length of the sequence, respectively.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output a single integer — the maximum possible value of _(i=1)^(k) popcount(a_i).
 *
 * ── Example Input ────────────────────────────────────────
 * 6
 * 2 1
 * 3 1
 * 6 2
 * 14142 137205
 * 1000000 100
 * 1000000 1000000
 *
 * ── Example Output ───────────────────────────────────────
 * 1
 * 2
 * 4
 * 14142
 * 1322
 * 1000000
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, n=2 and k=1. We can choose a = [1] or a = [2]. In both cases, the sum of popcounts is 1.
 * In the second test case, n=3 and k=1. We can choose a = [3], since (3)_2 = (11)_2, popcount(3) = 2.
 * In the third test case, n=6 and k=2. We can choose a = [3, 3]. The sum is 3 + 3 = 6 ≤ 6, and the total popcount is popcount(3) + popcount(3) = 2 + 2 = 4.
 *
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;

    long long ans = 0;
    long long left = n;
    long long addCost = 1;

    while (addCost <= left)
    {
        long long cnt = left / addCost;

        if (cnt > k)
        {
            cnt = k;
        }

        ans += cnt;
        left -= cnt * addCost;
        addCost *= 2;
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}