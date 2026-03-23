/*
 * Problem: C. Vasilije in Cacak
 * Contest: 1878 | Problem C
 * Link: https://codeforces.com/contest/1878/problem/C
 *
 * --- Input ---
 * The first line contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases. The only line of each test case contains three integers $$$n$$$, $$$k$$$ and $$$x$$$ ($$$1 \le n \le 2 \cdot 10^5$$$, $$$1 \le k \le n$$$, $$$1 \le x \le 4 \cdot 10^{10}$$$) — the maximum element he can choose, the number of elements he can choose and the sum he has to reach. Note that the sum of $$$n$$$ over all test cases may exceed $$$2 \cdot 10^5$$$. Output For each test case output one line: &quot; YES &quot;, if it is possible to choose $$$k$$$ distinct integers between $$$1$$$ and $$$n$$$, such that their sum is equal to $$$x$$$, and &quot; NO &quot;, if it isn't. You can output the answer in any case (for example, the strings &quot; yEs &quot;, &quot; yes &quot;, &quot; Yes &quot;, and &quot; YES &quot; will be recognized as a positive answer). Example Input 12 5 3 10 5 3 3 10 10 55 6 5 20 2 1 26 187856 87856 2609202300 200000 190000 19000000000 28 5 2004 2 2 2006 9 6 40 47202 32455 613407217 185977 145541 15770805980 Output YES NO YES YES NO NO YES NO NO NO YES YES
 *
 * --- Output ---
 * For each test case output one line: &quot; YES &quot;, if it is possible to choose $$$k$$$ distinct integers between $$$1$$$ and $$$n$$$, such that their sum is equal to $$$x$$$, and &quot; NO &quot;, if it isn't. You can output the answer in any case (for example, the strings &quot; yEs &quot;, &quot; yes &quot;, &quot; Yes &quot;, and &quot; YES &quot; will be recognized as a positive answer). Example Input 12 5 3 10 5 3 3 10 10 55 6 5 20 2 1 26 187856 87856 2609202300 200000 190000 19000000000 28 5 2004 2 2 2006 9 6 40 47202 32455 613407217 185977 145541 15770805980 Output YES NO YES YES NO NO YES NO NO NO YES YES
 *
 * --- Example Input ---
 * 12 5 3 10 5 3 3 10 10 55 6 5 20 2 1 26 187856 87856 2609202300 200000 190000 19000000000 28 5 2004 2 2 2006 9 6 40 47202 32455 613407217 185977 145541 15770805980
 *
 * --- Example Output ---
 * YES NO YES YES NO NO YES NO NO NO YES YES
 *
 */

#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k,x;

        cin >> n >> k >> x;
        long long max_sum = (n * (n + 1) ) / 2 - ((n - k) * (n - k + 1) )/ 2;
        long long min_sum = (k * (k + 1) ) / 2;

        if(min_sum <= x && x <= max_sum){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}