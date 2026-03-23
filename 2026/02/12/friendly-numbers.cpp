/*
 * Problem: A. Friendly Numbers
 * Contest: 2197/A | Link: https://codeforces.com/contest/2197/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * For an integer x, we call another integer y friendly if the following condition holds:
 * 
 * • y - d(y) = x, where d(y) is the sum of the digits of y. For a given integer x, determine how many friendly numbers it has.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 500). The description of the test cases follows.
 * Each test case consists of a single line containing one integer x (1 ≤ x ≤ 10^(9)).
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output one integer — the answer to the problem.
 *
 * ── Example Input ────────────────────────────────────────
 * 3
 * 1
 * 18
 * 998244360
 *
 * ── Example Output ───────────────────────────────────────
 * 0
 * 10
 * 10
 *
 * ── Notes ────────────────────────────────────────────────
 * The number 1 does not have any friendly numbers.
 * The number 18 has 10 friendly numbers: These are all the numbers from 20 to 29. For example, 20 - d(20) = 20 - 2 = 18.
 * The number 998\,244\,360 has 10 friendly numbers:
 * 
 * • 998\,244\,400
 * • 998\,244\,401
 * • 998\,244\,402
 * • 998\,244\,403
 * • 998\,244\,404
 * • 998\,244\,405
 * • 998\,244\,406
 * • 998\,244\,407
 * • 998\,244\,408
 * • 998\,244\,409
 *
 */

#include<bits/stdc++.h>
using namespace std;

int summation(int n){
    int sum = 0 ;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{   int x;
    cin>> x;
     
    //this is the min req if any number is not divisible with 9 cant be rep by other numbers 
    if(x % 9 != 0){
        cout << 0 << endl;
        return;
    }
    
    long long start = x / 10;

    bool found = false;

    //this is from the rule that any number can be obtained using the formula 10K + r = num
    //given equation y−d(y)=x, where d(y) is the sum of the digits of y
    // (10k + r) - (d(k) + r) = x
    // 10k - d(k) = x;

    //but .. what is the minimum range should be 
    //what is the k range .. k = x / 10 + d(k) / 10;
    //so the min should be x / 10 and what about the max..if we consider any number what is the max if all are 9 taht is 9 * 9 = 81
    //so d(k) / 10 will be even smaller so the max can be like next 20 numbers

    for(long long k = start ; k <= start + 20 ; k++){
        if(10 * k - summation(k) == x){
            found = true;
            break;
        }
    }
    
    //if we can get that k we can get the condition correct
    if(found){
        cout << 10 << endl;
    }
    else{
        cout << 0 << endl;
    }
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