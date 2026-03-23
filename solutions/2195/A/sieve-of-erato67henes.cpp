/*
 * Problem: A. Sieve of Erato67henes
 * Contest: 2195 | Problem A
 * Link: https://codeforces.com/contest/2195/problem/A
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 5$$$). The second line of each test case contains $$$n$$$ positive integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \le a_i \le 67$$$). Output If it is possible to select elements so that their product is $$$67$$$, output &quot; YES &quot; on one line. Otherwise, output &quot; NO &quot; on one line. You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses. Example Input 2 5 1 7 6 7 67 5 1 3 5 7 8 Output YES NO
 *
 * --- Output ---
 * If it is possible to select elements so that their product is $$$67$$$, output &quot; YES &quot; on one line. Otherwise, output &quot; NO &quot; on one line. You can output the answer in any case. For example, the strings &quot; yEs &quot;, &quot; yes &quot;, and &quot; Yes &quot; will also be recognized as positive responses. Example Input 2 5 1 7 6 7 67 5 1 3 5 7 8 Output YES NO
 *
 * --- Example Input ---
 * 2 5 1 7 6 7 67 5 1 3 5 7 8
 *
 * --- Example Output ---
 * YES NO
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