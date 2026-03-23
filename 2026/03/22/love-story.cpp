/*
 * Problem: A. Love Story
 * Contest: 1829/A | Link: https://codeforces.com/contest/1829/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * Timur loves codeforces. That's why he has a string $$$s$$$ having length $$$10$$$ made containing only lowercase Latin letters. Timur wants to know how many indices string $$$s$$$ differs from the string &quot; codeforces &quot;. For example string $$$s =$$$ &quot; co ol for s e z &quot; differs from &quot; codeforces &quot; in $$$4$$$ indices, shown in bold. Help Timur by finding the number of indices where string $$$s$$$ differs from &quot; codeforces &quot;. Note that you can't reorder the characters in the string $$$s$$$.
 *
 * ── Input ────────────────────────────────────────────────
 * The first line contains a single integer $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of test cases. Each test case is one line and contains the string $$$s$$$, consisting of exactly $$$10$$$ lowercase Latin characters.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output a single integer — the number of indices where string $$$s$$$ differs.
 *
 * ── Example Input ────────────────────────────────────────
 * 5 coolforsez cadafurcie codeforces paiuforces forcescode
 *
 * ── Example Output ───────────────────────────────────────
 * 4 5 0 4 9
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t;
    while(t--){
        string s;
        string original = "codeforces";
        cin >> s;

        int count = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != original[i]){
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}