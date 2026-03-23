/*
 * Problem: A. Business trip
 * Contest: 149 | Problem A
 * Link: https://codeforces.com/contest/149/problem/A
 *
 * --- Input ---
 * The first line contains exactly one integer k ( 0 ≤ k ≤ 100 ). The next line contains twelve space-separated integers: the i -th ( 1 ≤ i ≤ 12 ) number in the line represents a i ( 0 ≤ a i ≤ 100 ). Output Print the only integer — the minimum number of months when Petya has to water the flower so that the flower grows no less than by k centimeters. If the flower can't grow by k centimeters in a year, print -1 . Examples Input 5 1 1 1 1 2 2 3 2 2 1 1 1 Output 2 Input 0 0 0 0 0 0 0 0 1 1 2 3 0 Output 0 Input 11 1 1 4 1 1 5 1 1 4 1 1 1 Output 3
 *
 * --- Output ---
 * Print the only integer — the minimum number of months when Petya has to water the flower so that the flower grows no less than by k centimeters. If the flower can't grow by k centimeters in a year, print -1 . Examples Input 5 1 1 1 1 2 2 3 2 2 1 1 1 Output 2 Input 0 0 0 0 0 0 0 0 1 1 2 3 0 Output 0 Input 11 1 1 4 1 1 5 1 1 4 1 1 1 Output 3
 *
 * --- Example Input ---
 * 5 1 1 1 1 2 2 3 2 2 1 1 1 | 0 0 0 0 0 0 0 0 1 1 2 3 0 | 11 1 1 4 1 1 5 1 1 4 1 1 1
 *
 * --- Example Output ---
 * 2 | 0 | 3
 *
 * --- Notes ---
 * Let's consider the first sample test. There it is enough to water the flower during the seventh and the ninth month. Then the flower grows by exactly five centimeters. In the second sample Petya's parents will believe him even if the flower doesn't grow at all ( k = 0 ). So, it is possible for Petya not to water the flower at all.
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k ;
    cin >> k;
    vector<int> a(12);
    
    for(int i = 0 ; i < 12 ; i++){
        cin >> a[i];
    }
    
    sort(a.rbegin(),a.rend());

    int currentgrowth = 0;
    int count = 0;
    int i = 0;
    while(currentgrowth < k && i < 12){
        currentgrowth += a[i];
        count++;
        i++;
    }
    
    
    if(currentgrowth < k){
        cout << -1 << endl;
    }
    else{
        cout << count << endl;
    }
    return 0;
}