/*
 * Problem: A. Sieve of Erato67henes
 * Contest: 2195/A | Link: https://codeforces.com/contest/2195/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * You are given n positive integers a_1,a_2,...,a_n.
 * Please determine if it is possible to select any number of elements in a, so that their product is 67.
 * Note that you may not select zero elements, as the product of zero elements is not defined in this problem.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
 * The first line of each test case contains a single integer n (1 ≤ n ≤ 5).
 * The second line of each test case contains n positive integers a_1,a_2,...,a_n (1 ≤ a_i ≤ 67).
 *
 * ── Output ───────────────────────────────────────────────
 * If it is possible to select elements so that their product is 67, output &quot; YES &quot; on one line. Otherwise, output &quot; NO &quot; on one line.
 * You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses.
 *
 * ── Example Input ────────────────────────────────────────
 * 2
 * 5
 * 1 7 6 7 67
 * 5
 * 1 3 5 7 8
 *
 * ── Example Output ───────────────────────────────────────
 * YES
 * NO
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, you can select a_1 and a_5 to get a_1· a_5 = 1 · 67 = 67.
 * In the second test case, it is impossible to select any number of elements so that their product is 67.
 *
 */

#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] == 67) {
            flag= true;
        }
    }

    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    
    return 0;
}