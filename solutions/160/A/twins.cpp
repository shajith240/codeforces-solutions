/*
 * Problem: A. Twins
 * Contest: 160 | Problem A
 * Link: https://codeforces.com/contest/160/problem/A
 *
 * --- Input ---
 * The first line contains integer n ( 1 ≤ n ≤ 100 ) — the number of coins. The second line contains a sequence of n integers a 1 , a 2 , ..., a n ( 1 ≤ a i ≤ 100 ) — the coins' values. All numbers are separated with spaces. Output In the single line print the single number — the minimum needed number of coins. Examples Input 2 3 3 Output 2 Input 3 2 1 2 Output 2
 *
 * --- Output ---
 * In the single line print the single number — the minimum needed number of coins. Examples Input 2 3 3 Output 2 Input 3 2 1 2 Output 2
 *
 * --- Example Input ---
 * 2 3 3 | 3 2 1 2
 *
 * --- Example Output ---
 * 2 | 2
 *
 * --- Notes ---
 * In the first sample you will have to take 2 coins (you and your twin have sums equal to 6, 0 correspondingly). If you take 1 coin, you get sums 3, 3 . If you take 0 coins, you get sums 0, 6 . Those variants do not satisfy you as your sum should be strictly more that your twins' sum. In the second sample one coin isn't enough for us, too. You can pick coins with values 1, 2 or 2, 2 . In any case, the minimum number of coins equals 2 .
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n;
    vector<int> a(n);
    int totalsum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        totalsum += a[i];
    }
    
    sort(a.rbegin(),a.rend());
    int mySum = 0;
    int count = 0;
    int i = 0;
    while(mySum <= (totalsum - mySum)){
        mySum += a[i];
        count++;
        i++;
    }
    
    cout << count << endl;
    return 0;
}