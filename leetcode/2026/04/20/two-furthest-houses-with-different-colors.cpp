/*
 * Problem: Two Furthest Houses With Different Colors
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 * Language: cpp
 * Topics: Array, Greedy
 * 
 * ── Problem ────────────────────────────────────────────
 * There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n , where colors[i] represents the color of the i th house.
 * Return the maximum distance between two houses with different colors .
 * The distance between the i th and j th houses is abs(i - j) , where abs(x) is the absolute value of x .
 * Example 1:
 * Input: colors = [ 1 ,1,1, 6 ,1,1,1]
 * Output: 3
 * Explanation: In the above image, color 1 is blue, and color 6 is red.
 * The furthest two houses with different colors are house 0 and house 3.
 * House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
 * Note that houses 3 and 6 can also produce the optimal answer.
 * Example 2:
 * Input: colors = [ 1 ,8,3,8, 3 ]
 * Output: 4
 * Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
 * The furthest two houses with different colors are house 0 and house 4.
 * House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
 * Example 3:
 * Input: colors = [ 0 , 1 ]
 * Output: 1
 * Explanation: The furthest two houses with different colors are house 0 and house 1.
 * House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
 * Constraints:
 * • n == colors.length
 * • 2 <= n <= 100
 * • 0 <= colors[i] <= 100
 * • Test data are generated such that at least two houses have different colors.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: The constraints are small. Can you try the combination of every two houses?
 * Hint 2: Greedily, the maximum distance will come from either the pair of the leftmost house and possibly some house on the right with a different color, or the pair of the rightmost house and possibly some house on the left with a different color.
 * 
 */

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;
        
        // 1. Compare against the first house (index 0)
        for(int i = n - 1; i >= 0; i--) {
            if(colors[i] != colors[0]) {
                max_dist = max(max_dist, i);
                break; // Found the furthest from index 0, stop looking
            }
        }
        
        // 2. Compare against the last house (index n - 1)
        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[n - 1]) {
                max_dist = max(max_dist, (n - 1) - i);
                break; // Found the furthest from index n-1, stop looking
            }
        }
        
        return max_dist;
    }
};