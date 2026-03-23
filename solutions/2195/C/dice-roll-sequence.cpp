/*
 * Problem: C. Dice Roll Sequence
 * Contest: 2195 | Problem C
 * Link: https://codeforces.com/contest/2195/problem/C
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 3 \cdot 10^5$$$). The second line of each test case contains $$$n$$$ integers $$$a_1,a_2,\ldots,a_n$$$ ($$$1 \le a_i \le 6$$$). It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$3 \cdot 10^5$$$. Output For each test case, output the minimum number of operations required to make $$$a$$$ a dice roll sequence. Example Input 3 3 1 4 2 4 3 4 6 3 10 6 1 4 3 1 3 2 5 4 4 Output 0 1 4
 *
 * --- Output ---
 * For each test case, output the minimum number of operations required to make $$$a$$$ a dice roll sequence. Example Input 3 3 1 4 2 4 3 4 6 3 10 6 1 4 3 1 3 2 5 4 4 Output 0 1 4
 *
 * --- Example Input ---
 * 3 3 1 4 2 4 3 4 6 3 10 6 1 4 3 1 3 2 5 4 4
 *
 * --- Example Output ---
 * 0 1 4
 *
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(7, 0);

    for (int face = 1; face <= 6; face++) {
        
        //if the face mathches what already there cost is 0 otherwise cost is 1..
        if (a[0] == face) {
            dp[face] = 0;
        } else {
            dp[face] = 1;
        }
    }

    
    for (int i = 1; i < n; i++) {
        // n_dp will hold the costs for the CURRENT dice
        vector<int> n_dp(7, 1e9); 

        for (int curr_face = 1; curr_face <= 6; curr_face++) {
           
            int cost_to_change = (a[i] == curr_face) ? 0 : 1;

            for (int prev_face = 1; prev_face <= 6; prev_face++) {
                
                if (curr_face != prev_face && curr_face + prev_face != 7) {
                    
                    n_dp[curr_face] = min(n_dp[curr_face], dp[prev_face] + cost_to_change);
                }
            }
        }
        // Move to the next step
        dp = n_dp;
    }

    //returning the min value in the dp
    int ans = 1e9;
    for (int face = 1; face <= 6; face++) {
        ans = min(ans, dp[face]);
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}