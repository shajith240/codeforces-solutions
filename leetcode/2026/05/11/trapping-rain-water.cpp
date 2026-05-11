/*
 * Problem: Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * Language: cpp
 * Topics: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
 * 
 * ── Problem ────────────────────────────────────────────
 * Given n non-negative integers representing an elevation map where the width of each bar is 1 , compute how much water it can trap after raining.
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * Constraints:
 * • n == height.length
 * • 1 <= n <= 2 * 10 4
 * • 0 <= height[i] <= 10 5
 * 
 */

class Solution {
public:
    vector<int> getleftMax(vector<int>& height,int &n){

        vector<int>leftmax(n);

        leftmax[0] = height[0];

        for(int i = 1;  i < n ; i++){
            leftmax[i] = max(leftmax[i - 1],height[i]);
        }
        return leftmax;
    }

    vector<int> getrightMax(vector<int>& height, int &n){
        vector<int>rightmax(n);

        rightmax[n - 1] = height[n-1];

        for(int i = n - 2 ; i >= 0 ; i--){
            rightmax[i] = max(rightmax[i + 1] , height[i]);
        }

        return rightmax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        
        int sum = 0;
        vector<int>leftMax = getleftMax(height,n);
        vector<int>rightMax = getrightMax(height,n);
        for(int i = 0 ; i < n ; i++){
        
            int h = min(leftMax[i],rightMax[i]) - height[i];

            sum += h;
        }
        return sum;
    }
};