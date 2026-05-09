/*
 * Problem: Product of Array Except Self
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 * Language: cpp
 * Topics: Array, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array nums , return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i] .
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * Constraints:
 * • 2 <= nums.length <= 10 5
 * • -30 <= nums[i] <= 30
 * • The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Think how you can efficiently utilize prefix and suffix products to calculate the product of all elements except self for each index. Can you pre-compute the prefix and suffix products in linear time to avoid redundant calculations?
 * Hint 2: Can you minimize additional space usage by reusing memory or modifying the input array to store intermediate results?
 * 
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefixsum(nums.size());
        vector<int> suffixsum(nums.size());

        for(int i = 0; i < nums.size(); i++) {

            if(i == 0) {
                prefixsum[i] = nums[i];
            }
            else {
                prefixsum[i] = prefixsum[i - 1] * nums[i];
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--) {

            if(i == nums.size() - 1) {
                suffixsum[i] = nums[nums.size() - 1];
            }
            else {
                suffixsum[i] = suffixsum[i + 1] * nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++) {

            if(i == 0) {
                nums[i] = suffixsum[i + 1];
            }

            else if(i == nums.size() - 1) {
                nums[i] = prefixsum[nums.size() - 2];
            }

            else {
                nums[i] = prefixsum[i - 1] * suffixsum[i + 1];
            }
        }

        return nums;
    }
};