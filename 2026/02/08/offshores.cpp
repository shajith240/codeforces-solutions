/*
 * Problem: B. Offshores
 * Contest: 2194/B | Link: https://codeforces.com/contest/2194/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * Mark loves money very much, and he keeps most of it in the bank. He stores his money in $$$n$$$ different banks. In the $$$i$$$-th bank, he has $$$a_i$$$ rubles. One day, Mark decided to gather all his money in one bank, so he will be transferring money from one bank account to another. All interbank transfers are arranged the same way: he can transfer only $$$x$$$ rubles in one transfer, and considering all fees, $$$y$$$ rubles will be credited to the other account (since banks want to make a profit, it holds that $$$y \leq x$$$). It is possible that Mark will not be able to transfer all his money to one bank, but he wants to find the maximum number of rubles that can end up in any bank.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains three integers $$$n$$$, $$$x$$$, and $$$y$$$ ($$$2 \le n \le 2 \cdot 10^5$$$, $$$1 \le y \le x \le 10^9$$$) — the number of banks, the transfer amount, and the credited amount. The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le 10^9$$$) — the initial amount of rubles in each bank. It is guaranteed that the sum of the values of $$$n$$$ across all test cases does not exceed $$$2 \cdot 10^5$$$.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output a single number — the maximum number of rubles that can be obtained in any bank.
 *
 * ── Example Input ────────────────────────────────────────
 * 6 4 5 4 10 9 8 7 5 13 11 47 52 64 13 91 2 1 1 1000 1000 3 15 14 34 43 52 6 7 6 15 17 14 15 12 16 2 15 10 45 44
 *
 * ── Example Output ───────────────────────────────────────
 * 25 229 2000 113 72 74
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, the optimal sequence of transfers may look as follows: $$$$$$ 1\to4,\; 1\to4,\; 4\to3,\; 4\to3,\; 4\to3,\; 3\to2,\; 3\to2,\; 3\to2,\; 3\to2. $$$$$$ Let's show the changes in sums after each step: $$$$$$ (10,9,8,7) $$$$$$ $$$$$$ \xrightarrow{1\to4} (5,9,8,11) \xrightarrow{1\to4} (0,9,8,15) $$$$$$ $$$$$$ \xrightarrow{4\to3} (0,9,12,10) \xrightarrow{4\to3} (0,9,16,5) \xrightarrow{4\to3} (0,9,20,0) $$$$$$ $$$$$$ \xrightarrow{3\to2} (0,13,15,0) \xrightarrow{3\to2} (0,17,10,0) \xrightarrow{3\to2} (0,21,5,0) \xrightarrow{3\to2} (0,25,0,0). $$$$$$ As a result, in one bank (specifically the second one), it is possible to obtain $$$25$$$ rubles, and this value is the answer for this test case. In the third test case, it is possible to transfer one ruble from the first bank to the second bank $$$1000$$$ times and obtain $$$2000$$$ rubles in the second bank.
 *
 */

#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n ;
    long long x , y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    
    long long canBeTransfred = 0;

    for(int i = 0 ; i < n ;i++){
        cin >> a[i];

        canBeTransfred += (a[i] / x) * y;
    }
    

    long long maxMoneyCanTransfer = 0;
    for(int i = 0 ; i < n ; i++){
        
        long long currentSum = a[i] + (canBeTransfred - (a[i] / x) * y);

        maxMoneyCanTransfer = max(maxMoneyCanTransfer,currentSum);
    }
    
    cout << maxMoneyCanTransfer << endl;
}
int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}