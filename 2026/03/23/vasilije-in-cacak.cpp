/*
 * Problem: C. Vasilije in Cacak
 * Contest: 1878/C | Link: https://codeforces.com/contest/1878/problem/C
 *
 * ── Problem ──────────────────────────────────────────────
 * Aca and Milovan, two fellow competitive programmers, decided to give Vasilije a problem to test his skills.
 * Vasilije is given three positive integers: n, k, and x, and he has to determine if he can choose k distinct integers between 1 and n, such that their sum is equal to x.
 * Since Vasilije is now in the weirdest city in Serbia where Aca and Milovan live, Cacak, the problem seems weird to him. So he needs your help with this problem.
 *
 * ── Input ────────────────────────────────────────────────
 * The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
 * The only line of each test case contains three integers n, k and x (1 ≤ n ≤ 2 · 10^5, 1 ≤ k ≤ n, 1 ≤ x ≤ 4 · 10^(10)) — the maximum element he can choose, the number of elements he can choose and the sum he has to reach.
 * Note that the sum of n over all test cases may exceed 2 · 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case output one line: &quot; YES &quot;, if it is possible to choose k distinct integers between 1 and n, such that their sum is equal to x, and &quot; NO &quot;, if it isn't.
 * You can output the answer in any case (for example, the strings &quot; yEs &quot;, &quot; yes &quot;, &quot; Yes &quot;, and &quot; YES &quot; will be recognized as a positive answer).
 *
 * ── Example Input ────────────────────────────────────────
 * 12
 * 5 3 10
 * 5 3 3
 * 10 10 55
 * 6 5 20
 * 2 1 26
 * 187856 87856 2609202300
 * 200000 190000 19000000000
 * 28 5 2004
 * 2 2 2006
 * 9 6 40
 * 47202 32455 613407217
 * 185977 145541 15770805980
 *
 * ── Example Output ───────────────────────────────────────
 * YES
 * NO
 * YES
 * YES
 * NO
 * NO
 * YES
 * NO
 * NO
 * NO
 * YES
 * YES
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case n = 5,\ k=3,\ x=10, so we can choose the numbers: 2, 3, 5, whose sum is 10, so the answer is &quot; YES &quot;.
 * In the second test case n = 5, \ k=3, \ x=3, there is no three numbers which satisfies the condition, so the answer is &quot; NO &quot;. It can be shown that there are no three numbers whose sum is 3.
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