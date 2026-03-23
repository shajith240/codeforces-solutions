/*
 * Problem: A. Flip Flops
 * Contest: 2209 | Problem A
 * Link: https://codeforces.com/contest/2209/problem/A
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 500$$$). The description of the test cases follows. The first line of each test case contains three integers $$$n$$$, $$$c$$$ and $$$k$$$ ($$$1 \le n \le 100$$$, $$$0 \le c,k \le 10 ^ 9$$$). The second line contains $$$n$$$ integers $$$a_1,a_2,\ldots,a_n$$$ ($$$0\le a_i\le 10 ^ 9$$$). Output For each test case, output an integer — the maximum possible combat power. Example Input 10 1 12 23 21 1 8 4 5 1 3 4 16 3 6 3 14 9 11 5 9 2 20 16 18 16 11 5 18 30 1 2 93 84 2 7 29 13 2 9 38 4 7 1 6 10 9 2 8 1 8 11 17 3 14 16 20 10 10 192 109 1 9 20 9 829 3 87 1 283 7 10 1000000000 1000000000 19 1000000000 1 9 2 3 8 1 2 3 Output 12 16 3 6 9 53 109 119 721 3000000048
 *
 * --- Output ---
 * For each test case, output an integer — the maximum possible combat power. Example Input 10 1 12 23 21 1 8 4 5 1 3 4 16 3 6 3 14 9 11 5 9 2 20 16 18 16 11 5 18 30 1 2 93 84 2 7 29 13 2 9 38 4 7 1 6 10 9 2 8 1 8 11 17 3 14 16 20 10 10 192 109 1 9 20 9 829 3 87 1 283 7 10 1000000000 1000000000 19 1000000000 1 9 2 3 8 1 2 3 Output 12 16 3 6 9 53 109 119 721 3000000048
 *
 * --- Example Input ---
 * 10 1 12 23 21 1 8 4 5 1 3 4 16 3 6 3 14 9 11 5 9 2 20 16 18 16 11 5 18 30 1 2 93 84 2 7 29 13 2 9 38 4 7 1 6 10 9 2 8 1 8 11 17 3 14 16 20 10 10 192 109 1 9 20 9 829 3 87 1 283 7 10 1000000000 1000000000 19 1000000000 1 9 2 3 8 1 2 3
 *
 * --- Example Output ---
 * 12 16 3 6 9 53 109 119 721 3000000048
 *
 */

#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long c, k;
    cin >> n >> c >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        
        if (a[i] <= c) {
           
            long long add = min(k, c - a[i]);
            
            
            k -= add;
            
            
            c += a[i] + add;
        } else {
            
            break;
        }
    }
    
    cout << c << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}