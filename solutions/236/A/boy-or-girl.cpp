/*
 * Problem: A. Boy or Girl
 * Contest: 236 | Problem A
 * Link: https://codeforces.com/contest/236/problem/A
 *
 * --- Input ---
 * The first line contains a non-empty string, that contains only lowercase English letters — the user name. This string contains at most 100 letters. Output If it is a female by our hero's method, print &quot; CHAT WITH HER! &quot; (without the quotes), otherwise, print &quot; IGNORE HIM! &quot; (without the quotes). Examples Input wjmzbmr Output CHAT WITH HER! Input xiaodao Output IGNORE HIM! Input sevenkplus Output CHAT WITH HER!
 *
 * --- Output ---
 * If it is a female by our hero's method, print &quot; CHAT WITH HER! &quot; (without the quotes), otherwise, print &quot; IGNORE HIM! &quot; (without the quotes). Examples Input wjmzbmr Output CHAT WITH HER! Input xiaodao Output IGNORE HIM! Input sevenkplus Output CHAT WITH HER!
 *
 * --- Example Input ---
 * wjmzbmr | xiaodao | sevenkplus
 *
 * --- Example Output ---
 * CHAT WITH HER! | IGNORE HIM! | CHAT WITH HER!
 *
 * --- Notes ---
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
