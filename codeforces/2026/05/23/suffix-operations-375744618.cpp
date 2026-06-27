/*
 * Problem: B. Suffix Operations
 * Contest: 1453/B | Link: https://codeforces.com/contest/1453/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * Gildong has an interesting machine that has an array a with n integers. The machine supports two kinds of operations:
 * 
 * • Increase all elements of a suffix of the array by 1.
 * • Decrease all elements of a suffix of the array by 1. A suffix is a subsegment (contiguous elements) of the array that contains a_n. In other words, for all i where a_i is included in the subsegment, all a_j's where i j ≤ n must also be included in the subsegment.
 * Gildong wants to make all elements of a equal — he will always do so using the minimum number of operations necessary. To make his life even easier, before Gildong starts using the machine, you have the option of changing one of the integers in the array to any other integer. You are allowed to leave the array unchanged. You want to minimize the number of operations Gildong performs. With your help, what is the minimum number of operations Gildong will perform?
 * Note that even if you change one of the integers in the array, you should not count that as one of the operations because Gildong did not perform it.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains one or more test cases. The first line contains the number of test cases t (1 ≤ t ≤ 1000).
 * Each test case contains two lines. The first line of each test case consists of an integer n (2 ≤ n ≤ 2 · 10^5) — the number of elements of the array a.
 * The second line of each test case contains n integers. The i-th integer is a_i (-5 · 10^8 ≤ a_i ≤ 5 · 10^8).
 * It is guaranteed that the sum of n in all test cases does not exceed 2 · 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, print one integer — the minimum number of operations Gildong has to perform in order to make all elements of the array equal.
 *
 * ── Example Input ────────────────────────────────────────
 * 7
 * 2
 * 1 1
 * 3
 * -1 0 2
 * 4
 * 99 96 97 95
 * 4
 * -3 -5 -2 1
 * 6
 * 1 4 3 2 4 1
 * 5
 * 5 0 0 0 5
 * 9
 * -367741579 319422997 -415264583 -125558838 -300860379 420848004 294512916 -383235489 425814447
 *
 * ── Example Output ───────────────────────────────────────
 * 0
 * 1
 * 3
 * 4
 * 6
 * 5
 * 2847372102
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first case, all elements of the array are already equal. Therefore, we do not change any integer and Gildong will perform zero operations.
 * In the second case, we can set a_3 to be 0, so that the array becomes [-1,0,0]. Now Gildong can use the 2-nd operation once on the suffix starting at a_2, which means a_2 and a_3 are decreased by 1, making all elements of the array -1.
 * In the third case, we can set a_1 to 96, so that the array becomes [96,96,97,95]. Now Gildong needs to:
 * 
 * • Use the 2-nd operation on the suffix starting at a_3 once, making the array [96,96,96,94].
 * • Use the 1-st operation on the suffix starting at a_4 2 times, making the array [96,96,96,96]. In the fourth case, we can change the array into [-3,-3,-2,1]. Now Gildong needs to:
 * 
 * • Use the 2-nd operation on the suffix starting at a_4 3 times, making the array [-3,-3,-2,-2].
 * • Use the 2-nd operation on the suffix starting at a_3 once, making the array [-3,-3,-3,-3].
 *
 */

#include <bits/stdc++.h>
using namespace std;

long long calculate(int i, vector<long long>& a) {
    long long front_gap = abs(a[i] - a[i-1]);
    long long back_gap = abs(a[i] - a[i+1]);
    
    long long new_gap = abs(a[i-1] - a[i+1]);
    
    return (front_gap + back_gap - new_gap);
}

int main() {
    // These two lines make cin/cout run much faster for large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        long long total_ops = 0;
        
        // 1. Calculate the total operations (Stop at n-1 to avoid out of bounds!)
        for(int i = 0; i < n - 1; i++){
            total_ops += abs(a[i] - a[i+1]);
        }
        
        long long best_saving = 0;
        
        // 2. Check the edge cases (first and last elements)
        best_saving = max(best_saving, abs(a[0] - a[1]));
        best_saving = max(best_saving, abs(a[n-1] - a[n-2]));
        
        // 3. Check all the middle elements using your formula
        for(int i = 1; i < n - 1; i++){
            best_saving = max(best_saving, calculate(i, a));
        }
        
        // 4. Print the final answer for this specific test case
        cout << total_ops - best_saving << "\n";
    }
    
    return 0;
}