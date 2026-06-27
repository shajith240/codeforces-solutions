/*
 * Problem: C. Number Game
 * Contest: 1749/C | Link: https://codeforces.com/contest/1749/problem/C
 *
 * ── Problem ──────────────────────────────────────────────
 * Alice and Bob are playing a game. They have an array of positive integers a of size n.
 * Before starting the game, Alice chooses an integer k ≥ 0. The game lasts for k stages, the stages are numbered from 1 to k. During the i-th stage, Alice must remove an element from the array that is less than or equal to k - i + 1. After that, if the array is not empty, Bob must add k - i + 1 to an arbitrary element of the array. Note that both Alice's move and Bob's move are two parts of the same stage of the game. If Alice can't delete an element during some stage, she loses. If the k-th stage ends and Alice hasn't lost yet, she wins.
 * Your task is to determine the maximum value of k such that Alice can win if both players play optimally. Bob plays against Alice, so he tries to make her lose the game, if it's possible.
 *
 * ── Input ────────────────────────────────────────────────
 * The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
 * The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the size of the array a.
 * The second line contains n integers a_1, a_2, ..., a_n (1 ≤ a_i ≤ n).
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, print one integer — the maximum value of k such that Alice can win if both players play optimally.
 *
 * ── Example Input ────────────────────────────────────────
 * 4
 * 3
 * 1 1 2
 * 4
 * 4 4 4 4
 * 1
 * 1
 * 5
 * 1 3 2 1 1
 *
 * ── Example Output ───────────────────────────────────────
 * 2
 * 0
 * 1
 * 3
 *
 */

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> a,int k){
    for(int i = 1 ; i <= k ; i++){

       sort(a.rbegin(),a.rend()); 

       bool alice_moved = false;
       
       for(int j = 0 ; j < a.size(); j++){
            if(a[j] <= k - i + 1){
                a.erase(a.begin() + j);
                alice_moved = true;
                break;
            }
        }

        if(!alice_moved){
            return false;
        }

        if(!a.empty()){
            a.pop_back();
        }   
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i< n ;i++){
        cin >> a[i];
    }

    int low = 0, high = n;
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(check(a,mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
          high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}