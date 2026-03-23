/*
 * Problem: A. Fox And Snake
 * Contest: 510 | Problem A
 * Link: https://codeforces.com/contest/510/problem/A
 *
 * --- Input ---
 * The only line contains two integers: n and m ( 3 ≤ n , m ≤ 50 ). n is an odd number. Output Output n lines. Each line should contain a string consisting of m characters. Do not output spaces. Examples Input 3 3 Output ### ..# ### Input 3 4 Output #### ...# #### Input 5 3 Output ### ..# ### #.. ### Input 9 9 Output ######### ........# ######### #........ ######### ........# ######### #........ #########
 *
 * --- Output ---
 * Output n lines. Each line should contain a string consisting of m characters. Do not output spaces. Examples Input 3 3 Output ### ..# ### Input 3 4 Output #### ...# #### Input 5 3 Output ### ..# ### #.. ### Input 9 9 Output ######### ........# ######### #........ ######### ........# ######### #........ #########
 *
 */

#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n , m ;
    cin >> n >> m;
    int oddCount = 1;
    for(int i = 0 ; i < n ; i++){

        if(i % 2 == 0){
           
            for(int j = 0 ; j < m ;j++){
                cout << '#';
            }
            cout << endl;
        }
        else{
            if(oddCount % 2 == 1){
                for(int j = 0 ; j < m - 1 ; j++){
                    cout << '.';
                }

                cout << "#";
                cout << endl;
                oddCount++;
            }
            else{
                cout << '#';
                for(int j = 0 ; j < m - 1 ; j++){
                    cout << '.';
                }
                cout << endl;
                oddCount++;
            }
        }

        
    }
}
int main(){
    solve();
    return 0;
}