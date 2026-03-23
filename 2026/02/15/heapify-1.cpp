/*
 * Problem: B. Heapify 1
 * Contest: 2195/B | Link: https://codeforces.com/contest/2195/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * You are given a permutation $$$a$$$ of length $$$n$$$$$$^{\text{∗}}$$$. You can perform the following operation any number of times (possibly zero): Select an index $$$i$$$ ($$$1 \le i \le \frac{n}{2}$$$), and swap $$$a_i$$$ and $$$a_{2i}$$$. For example, when $$$a=[1,4,2,3,5]$$$, you can swap $$$a_2$$$ and $$$a_4$$$ to make it $$$[1,3,2,4,5]$$$, but you cannot swap $$$a_2$$$ and $$$a_3$$$. Please determine if the sequence $$$a$$$ can be sorted in increasing order. $$$^{\text{∗}}$$$A permutation of length $$$n$$$ is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array), and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$ but there is $$$4$$$ in the array).
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 2 \cdot 10^5$$$). The second line of each test case contains $$$n$$$ distinct integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \le a_i \le n$$$). It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.
 *
 * ── Output ───────────────────────────────────────────────
 * If $$$a$$$ can be sorted in increasing order, output &quot; YES &quot; on a separate line. Otherwise, output &quot; NO &quot; on a separate line. You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses.
 *
 * ── Example Input ────────────────────────────────────────
 * 2 5 1 4 3 2 5 5 1 4 2 3 5
 *
 * ── Example Output ───────────────────────────────────────
 * YES NO
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, $$$a$$$ is $$$[1,4,3,2,5]$$$. You can sort $$$a$$$ in increasing order by swapping $$$a_2$$$ and $$$a_4$$$. Therefore, the answer is &quot; YES &quot;. In the second test case, $$$a$$$ is $$$[1,4,2,3,5]$$$. It is impossible to sort $$$a$$$ in increasing order. Therefore, the answer is &quot; NO &quot;.
 *
 */

#include<bits/stdc++.h>
using namespace std;

int g_odd(int n){
    
    while(n % 2 == 0){
        n  =  n / 2;
    }
    return n;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++){
        if(g_odd(i + 1) != g_odd(a[i])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES"<< endl;
  
}

int main()
{   
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}