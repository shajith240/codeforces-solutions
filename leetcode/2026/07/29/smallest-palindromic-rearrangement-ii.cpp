/*
 * Problem: Smallest Palindromic Rearrangement II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
 * Language: cpp
 * Topics: Hash Table, Math, String, Combinatorics, Counting
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a palindromic string s and an integer k .
 * Return the k-th lexicographically smallest palindromic permutation of s . If there are fewer than k distinct palindromic permutations, return an empty string.
 * Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 * Example 1:
 * Input: s = &quot;abba&quot;, k = 2
 * Output: &quot;baab&quot;
 * Explanation:
 * • The two distinct palindromic rearrangements of &quot;abba&quot; are &quot;abba&quot; and &quot;baab&quot; .
 * • Lexicographically, &quot;abba&quot; comes before &quot;baab&quot; . Since k = 2 , the output is &quot;baab&quot; .
 * Example 2:
 * Input: s = &quot;aa&quot;, k = 2
 * Output: &quot;&quot;
 * Explanation:
 * • There is only one palindromic rearrangement: &quot;aa&quot; .
 * • The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 * Example 3:
 * Input: s = &quot;bacab&quot;, k = 1
 * Output: &quot;abcba&quot;
 * Explanation:
 * • The two distinct palindromic rearrangements of &quot;bacab&quot; are &quot;abcba&quot; and &quot;bacab&quot; .
 * • Lexicographically, &quot;abcba&quot; comes before &quot;bacab&quot; . Since k = 1 , the output is &quot;abcba&quot; .
 * Constraints:
 * • 1 <= s.length <= 10 4
 * • s consists of lowercase English letters.
 * • s is guaranteed to be palindromic.
 * • 1 <= k <= 10 6
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Only build floor(n / 2) characters (the rest are determined by symmetry).
 * Hint 2: Count character frequencies and use half the counts for construction.
 * Hint 3: Incrementally choose each character (from smallest to largest) and calculate how many valid arrangements result if that character is chosen at the current index.
 * Hint 4: If the count is at least k , fix that character; otherwise, subtract the count from k and try the next candidate.
 * Hint 5: Use combinatorics to compute the number of permutations at each step.
 * 
 */

class Solution {
public:

    long long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        //5C3 == 5C2
        //5C2 == 5C(5-2) = 5C3
        r = min(r, n-r); //nCr == nC(n-r)

        long long result = 1;

        for(int i = 1; i <= r; i++) {//O(log2(k))
            result = result * (n - r + i)/i; //result is becoming twice

            if(result >= k) 
                return k;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2 == 1) { //odd length
            mid = s[n/2];
        }

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            if(n%2 == 1 && i == n/2) continue; //mid character reserverd for middle one
            count[s[i] - 'a']++;
        }

        //half frequency will be used to build halfResult
        for(int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i = 0; i < half; i++) { //O(n/2)
            //I am trying to fill ith position
            //What if I could never fill a character in ith position
            bool placedCharacter = false; //in ith position
            for(int j = 0; j < 26; j++) { //which character to put
                if(count[j] > 0) {
                    count[j] -= 1;

                    //count number of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for(int c = 0; c < 26; c++) {
                        if(count[c] > 0) {
                            ways *= nCr(letters, count[c], k); //log2(k)
                            letters -= count[c];
                        }

                        if(ways >= k) {
                            break;
                        }
                    }

                    if(ways >= k) { //this block contains my kth one
                        halfResult.push_back(j + 'a'); //fixed this character at ith position
                        placedCharacter = true;
                        break;
                    }

                    k -= ways; //when k >= ways
                    count[j] += 1;
                }
            }

            if(placedCharacter == false)
                return "";
        }

        //halfResult + mid + (reverse of halfResult)
        string rev = halfResult;
        reverse(begin(rev), end(rev)); //O(n/2)

        if(mid != ' ') {
            halfResult.push_back(mid);
        }

        return halfResult + rev;
    }
};