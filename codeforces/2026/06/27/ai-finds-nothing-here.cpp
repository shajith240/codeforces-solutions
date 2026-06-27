/*
 * Problem: B. AI Finds Nothing Here
 * Contest: 2240/B | Link: https://codeforces.com/contest/2240/problem/B
 *
 * ── Problem ──────────────────────────────────────────────
 * Hacks are disabled in this problem.
 * Milkcat2009 has a matrix a with n rows and m columns consisting of integers 0 and 1. The rows are numbered from 1 to n, and the columns are numbered from 1 to m. The element in the i-th row and j-th column is denoted as a_(i,j).
 * Milkcat2009's AI scans every single submatrix^(∗) of a consisting of r rows and c columns. The AI considers the matrix clean if the bitwise XOR sum of elements in each such submatrix is equal to 0.
 * Formally, the matrix a is valid if and only if for all 1 ≤ i ≤ n - r + 1 and 1 ≤ j ≤ m - c + 1: $$$_(x=i)^(i+r-1) _(y=j)^(j+c-1) a_(x,y) = 0where\oplusdenotes summation with the bitwise XOR operation .
 * Your task is, given various sets of integersn, m, r, c, to count the number of clean matrices ofnrows andmcolumns with respect to scanning dimensionsrandc. Since the answer can be very large, calculate it modulo998\,244\,353.^{\text{∗}}$$$A submatrix of a matrix is obtained by removing some rows (from the beginning and/or end) and/or columns (from the beginning and/or end) from the original matrix.
 *
 * ── Input ────────────────────────────────────────────────
 * Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
 * Each test case consists of a single line containing four integers n, m, r, c (1 ≤ r ≤ n ≤ 10^9, 1 ≤ c ≤ m ≤ 10^9), representing the dimensions of the matrix and the dimensions of the scanning area, respectively.
 *
 * ── Output ───────────────────────────────────────────────
 * For each test case, output a single integer representing the answer modulo 998\,244\,353.
 *
 * ── Example Input ────────────────────────────────────────
 * 8
 * 1 1 1 1
 * 2 3 1 2
 * 2 5 2 2
 * 3 5 2 2
 * 4 6 2 2
 * 100 14 52 6
 * 1000000000 1000000000 1000000000 1000000000
 * 1000000000 1000000000 1 1
 *
 * ── Example Output ───────────────────────────────────────
 * 1
 * 4
 * 64
 * 128
 * 512
 * 543661425
 * 121099884
 * 1
 *
 * ── Notes ────────────────────────────────────────────────
 * For the first test case. The only element a_(1,1) must satisfy a_(1,1) = 0. Since a_(1,1) must be 0, there is only 1 valid matrix: [0].
 * For the second test case.The condition requires the XOR sum of every 1 × 2 submatrix to be 0. This implies a_(i,j) a_(i,j+1) = 0, so a_(i,j) = a_(i,j+1) for all valid i,j. For each row, all elements must be equal. Thus, each row can be either [0, 0, 0] or [1, 1, 1]. With 2 rows, there are 2^2 =4 valid matrices.
 *
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long binpow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    
    while (exp > 0) {
        
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}


void solve()
{
  long long n, m, r, c;
    cin >> n >> m >> r >> c;
    
    
    long long totalSlots = n * m;
    

    long long freewillChoices = (n - r + 1) * (m - c + 1);
    

    long long free_vars = totalSlots - freewillChoices;
    

    cout << binpow(2, free_vars) << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}