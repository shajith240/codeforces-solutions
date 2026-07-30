/*
 * Problem: Maximum Product of Three Numbers
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Language: cpp
 * Topics: Array, Math, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array nums , find three numbers whose product is maximum and return the maximum product .
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 6
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 24
 * Example 3:
 * Input: nums = [-1,-2,-3]
 * Output: -6
 * Constraints:
 * • 3 <= nums.length <= 10 4
 * • -1000 <= nums[i] <= 1000
 * 
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());

        int positiveMul = nums[0] * nums[1] * nums[2];
        int negitiveMul = nums[n-1] * nums[n - 2] * nums[0];

        if(positiveMul > negitiveMul){
            return positiveMul;
        }
        return negitiveMul;
    }
};