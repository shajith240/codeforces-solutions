/*
 * Problem: Stone Game III
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/stone-game-iii/
 * Language: cpp
 * Topics: Array, Math, Dynamic Programming, Minimax, Game Theory, Zero-Sum Game
 * 
 * ── Problem ────────────────────────────────────────────
 * Alice and Bob continue their games with piles of stones. There are several stones arranged in a row , and each stone has an associated value which is an integer given in the array stoneValue .
 * Alice and Bob take turns, with Alice starting first. On each player&#39;s turn, that player can take 1 , 2 , or 3 stones from the first remaining stones in the row.
 * The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
 * The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
 * Assume Alice and Bob play optimally .
 * Return &quot;Alice&quot; if Alice will win, &quot;Bob&quot; if Bob will win, or &quot;Tie&quot; if they will end the game with the same score .
 * Example 1:
 * Input: stoneValue = [1,2,3,7]
 * Output: &quot;Bob&quot;
 * Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
 * Example 2:
 * Input: stoneValue = [1,2,3,-9]
 * Output: &quot;Alice&quot;
 * Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
 * If Alice chooses one pile her score will be 1 and the next move Bob&#39;s score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
 * If Alice chooses two piles her score will be 3 and the next move Bob&#39;s score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
 * Remember that both play optimally so here Alice will choose the scenario that makes her win.
 * Example 3:
 * Input: stoneValue = [1,2,3,6]
 * Output: &quot;Tie&quot;
 * Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
 * Constraints:
 * • 1 <= stoneValue.length <= 5 * 10 4
 * • -1000 <= stoneValue[i] <= 1000
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: The game can be mapped to minmax game. Alice tries to maximize the total score and Bob tries to minimize it.
 * Hint 2: Use dynamic programming to simulate the game. If the total score was 0 the game is "Tie", and if it has positive value then "Alice" wins, otherwise "Bob" wins.
 * 
 */

class Solution {
public:
    //the logic in this problem is that same yesterday problem but and extended version of 3 choices and we pick the maximum
    
    
    int recursive_function(int i,vector<int>& stoneValue,int n,vector<int>&dp){

int result = INT_MIN;
      if(i >= n){
        return 0;
      }        
if(dp[i]!=-1){
    return dp[i];
}
      result = max(result,stoneValue[i] - recursive_function(i+1,stoneValue,n,dp));
      if(i+1<n){
      result = max(result,stoneValue[i] + stoneValue[i+1] - recursive_function(i+2,stoneValue,n,dp));
      }
      if(i+2<n){
      result = max(result,stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - recursive_function(i+3,stoneValue,n,dp));
      }
      return dp[i]=result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp(n,-1);
        int ans = recursive_function(0,stoneValue,n,dp);
        if(ans > 0){
            return "Alice";
        }else if(ans < 0){
            return "Bob";
        }else{
            return "Tie";
        }  

    }
};