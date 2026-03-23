/*
 * Problem: A. Boy or Girl
 * Contest: 236/A | Link: https://codeforces.com/contest/236/problem/A
 *
 * ── Problem ──────────────────────────────────────────────
 * Those days, many boys use beautiful girls' photos as avatars in forums. So it is pretty hard to tell the gender of a user at the first glance. Last year, our hero went to a forum and had a nice chat with a beauty (he thought so). After that they talked very often and eventually they became a couple in the network.
 * But yesterday, he came to see &quot;her&quot; in the real world and found out &quot;she&quot; is actually a very strong man! Our hero is very sad and he is too tired to love again now. So he came up with a way to recognize users' genders by their user names.
 * This is his method: if the number of distinct characters in one's user name is odd, then he is a male, otherwise she is a female. You are given the string that denotes the user name, please help our hero to determine the gender of this user by his method.
 *
 * ── Input ────────────────────────────────────────────────
 * The first line contains a non-empty string, that contains only lowercase English letters — the user name. This string contains at most 100 letters.
 *
 * ── Output ───────────────────────────────────────────────
 * If it is a female by our hero's method, print &quot; CHAT WITH HER! &quot; (without the quotes), otherwise, print &quot; IGNORE HIM! &quot; (without the quotes).
 *
 * ── Example Input ────────────────────────────────────────
 * wjmzbmr | xiaodao | sevenkplus
 *
 * ── Example Output ───────────────────────────────────────
 * CHAT WITH HER! | IGNORE HIM! | CHAT WITH HER!
 *
 * ── Notes ────────────────────────────────────────────────
 * For the first example. There are 6 distinct characters in &quot; wjmzbmr &quot;. These characters are: &quot; w &quot;, &quot; j &quot;, &quot; m &quot;, &quot; z &quot;, &quot; b &quot;, &quot; r &quot;. So wjmzbmr is a female and you should print &quot; CHAT WITH HER! &quot;.
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    set<char> unique;

    for(int i = 0; i < n; i++){
        unique.insert(s[i]);
    }

    if(unique.size() % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}
