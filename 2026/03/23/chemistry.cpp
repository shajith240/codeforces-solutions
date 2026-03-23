/*
 * Problem: B. Chemistry
 * Contest: 1883/B | Link: https://codeforces.com/contest/1883/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * You are given a string s of length n, consisting of lowercase Latin letters, and an integer k.
 * You need to check if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome. Note that you can reorder the remaining characters in any way.
 * A palindrome is a string that reads the same forwards and backwards. For example, the strings &quot; z &quot;, &quot; aaa &quot;, &quot; aba &quot;, &quot; abccba &quot; are palindromes, while the strings &quot; codeforces &quot;, &quot; reality &quot;, &quot; ab &quot; are not.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test consists of multiple test cases. The first line contains a single integer t (1 ≤q t ≤q 10^4) — the number of the test cases. This is followed by their description.
 * The first line of each test case contains two integers n and k (0 ≤q k n ≤q 10^5) — the length of the string s and the number of characters to be deleted.
 * The second line of each test case contains a string s of length n, consisting of lowercase Latin letters.
 * It is guaranteed that the sum of n over all test cases does not exceed 2 · 10^5.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output &quot; YES &quot; if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome, and &quot; NO &quot; otherwise.
 * You can output the answer in any case (uppercase or lowercase). For example, the strings &quot; yEs &quot;, &quot; yes &quot;, &quot; Yes &quot;, and &quot; YES &quot; will be recognized as positive answers.
 *
 * ── Example Input ────────────────────────────────────────
 * 14
 * 1 0
 * a
 * 2 0
 * ab
 * 2 1
 * ba
 * 3 1
 * abb
 * 3 2
 * abc
 * 6 2
 * bacacd
 * 6 2
 * fagbza
 * 6 2
 * zwaafa
 * 7 2
 * taagaak
 * 14 3
 * ttrraakkttoorr
 * 5 3
 * debdb
 * 5 4
 * ecadc
 * 5 3
 * debca
 * 5 3
 * abaac
 *
 * ── Example Output ───────────────────────────────────────
 * YES
 * NO
 * YES
 * YES
 * YES
 * YES
 * NO
 * NO
 * YES
 * YES
 * YES
 * YES
 * NO
 * YES
 *
 * ── Notes ────────────────────────────────────────────────
 * In the first test case, nothing can be removed, and the string &quot; a &quot; is a palindrome.
 * In the second test case, nothing can be removed, but the strings &quot; ab &quot; and &quot; ba &quot; are not palindromes.
 * In the third test case, any character can be removed, and the resulting string will be a palindrome.
 * In the fourth test case, one occurrence of the character &quot; a &quot; can be removed, resulting in the string &quot; bb &quot;, which is a palindrome.
 * In the sixth test case, one occurrence of the characters &quot; b &quot; and &quot; d &quot; can be removed, resulting in the string &quot; acac &quot;, which can be rearranged to the string &quot; acca &quot;.
 * In the ninth test case, one occurrence of the characters &quot; t &quot; and &quot; k &quot; can be removed, resulting in the string &quot; aagaa &quot;, which is a palindrome.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> freq(26, 0); 
    for (char c : s) {
        freq[c - 'a']++;
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
        }
    }

    if (k >= odd_count - 1 && k <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}