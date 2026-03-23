/*
 * Problem: B. Heapify 1
 * Contest: 2195 | Problem B
 * Link: https://codeforces.com/contest/2195/problem/B
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 2 \cdot 10^5$$$). The second line of each test case contains $$$n$$$ distinct integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \le a_i \le n$$$). It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$. Output If $$$a$$$ can be sorted in increasing order, output &quot; YES &quot; on a separate line. Otherwise, output &quot; NO &quot; on a separate line. You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses. Example Input 2 5 1 4 3 2 5 5 1 4 2 3 5 Output YES NO
 *
 * --- Output ---
 * If $$$a$$$ can be sorted in increasing order, output &quot; YES &quot; on a separate line. Otherwise, output &quot; NO &quot; on a separate line. You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses. Example Input 2 5 1 4 3 2 5 5 1 4 2 3 5 Output YES NO
 *
 * --- Example Input ---
 * 2 5 1 4 3 2 5 5 1 4 2 3 5
 *
 * --- Example Output ---
 * YES NO
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