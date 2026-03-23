/*
 * Problem: B. Offshores
 * Contest: 2194 | Problem B
 * Link: https://codeforces.com/contest/2194/problem/B
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains three integers $$$n$$$, $$$x$$$, and $$$y$$$ ($$$2 \le n \le 2 \cdot 10^5$$$, $$$1 \le y \le x \le 10^9$$$) — the number of banks, the transfer amount, and the credited amount. The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le 10^9$$$) — the initial amount of rubles in each bank. It is guaranteed that the sum of the values of $$$n$$$ across all test cases does not exceed $$$2 \cdot 10^5$$$. Output For each test case, output a single number — the maximum number of rubles that can be obtained in any bank. Example Input 6 4 5 4 10 9 8 7 5 13 11 47 52 64 13 91 2 1 1 1000 1000 3 15 14 34 43 52 6 7 6 15 17 14 15 12 16 2 15 10 45 44 Output 25 229 2000 113 72 74
 *
 * --- Output ---
 * For each test case, output a single number — the maximum number of rubles that can be obtained in any bank. Example Input 6 4 5 4 10 9 8 7 5 13 11 47 52 64 13 91 2 1 1 1000 1000 3 15 14 34 43 52 6 7 6 15 17 14 15 12 16 2 15 10 45 44 Output 25 229 2000 113 72 74
 *
 * --- Example Input ---
 * 6 4 5 4 10 9 8 7 5 13 11 47 52 64 13 91 2 1 1 1000 1000 3 15 14 34 43 52 6 7 6 15 17 14 15 12 16 2 15 10 45 44
 *
 * --- Example Output ---
 * 25 229 2000 113 72 74
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