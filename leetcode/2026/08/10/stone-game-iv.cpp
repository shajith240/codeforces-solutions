/*
 * Problem: Stone Game IV
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/stone-game-iv/
 * Language: cpp
 * Topics: Math, Dynamic Programming, Minimax, Game Theory, Nim Game, Sprague–Grundy Theorem, Zero-Sum Game
 * 
 * ── Problem ────────────────────────────────────────────
 * Alice and Bob take turns playing a game, with Alice starting first.
 * Initially, there are n stones in a pile. On each player&#39;s turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
 * Also, if a player cannot make a move, he/she loses the game.
 * Given a positive integer n , return true if and only if Alice wins the game otherwise return false , assuming both players play optimally.
 * Example 1:
 * Input: n = 1
 * Output: true
 * Explanation: Alice can remove 1 stone winning the game because Bob doesn&#39;t have any moves.
 * Example 2:
 * Input: n = 2
 * Output: false
 * Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
 * Example 3:
 * Input: n = 4
 * Output: true
 * Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
 * Constraints:
 * • 1 <= n <= 10 5
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use dynamic programming to keep track of winning and losing states. Given some number of stones, Alice can win if she can force Bob onto a losing state.
 * 
 */

class Solution {
public:
    
    vector<int> t;

    bool solve(int n){
        if(n == 0){
            return false;
        }

        if(t[n] != -1){
           return t[n] == 1;
        }

        for(int k = 1 ; k*k <= n ; k++){
            if(solve(n - (k*k)) == false){
                
                t[n] = true;

                return true;
            }
        }
        
        t[n] = false;
        return false;
    }
    bool winnerSquareGame(int n) {
        t.assign(n+1,-1);
        return solve(n);
    }
};