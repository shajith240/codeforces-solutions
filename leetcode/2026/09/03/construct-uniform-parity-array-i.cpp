/*
 * Problem: Construct Uniform Parity Array I
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/construct-uniform-parity-array-i/
 * Language: cpp
 * Topics: Array, Math
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an array nums1 of n distinct integers.
 * You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even .
 * For each index i , you must choose exactly one of the following (in any order):
 * • nums2[i] = nums1[i]
 * • nums2[i] = nums1[i] - nums1[j] , for an index j != i
 * Return true if it is possible to construct such an array, otherwise, return false .
 * Example 1:
 * Input: nums1 = [2,3]
 * Output: true
 * Explanation:
 * • Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1 .
 * • Choose nums2[1] = nums1[1] = 3 .
 * • nums2 = [-1, 3] , and both elements are odd. Thus, the answer is true ​​​​​​​.
 * Example 2:
 * Input: nums1 = [4,6]
 * Output: true
 * Explanation: ​​​​​​​
 * • Choose nums2[0] = nums1[0] = 4 .
 * • Choose nums2[1] = nums1[1] = 6 .
 * • nums2 = [4, 6] , and all elements are even. Thus, the answer is true .
 * Constraints:
 * • 1 <= n == nums1.length <= 100
 * • 1 <= nums1[i] <= 100
 * • nums1 consists of distinct integers.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: There is only one possible answer.
 * 
 */

class Solution {
public:
    bool construct_odd(vector<int>& nums) {
        int n = nums.size();
                    bool flag = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 1) {
                for (int j = i + 1; j < n; j++) {
                    if ((nums[i] - nums[j]) % 2 != 0) {
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
            }
        }
        return flag;
    }

    bool construct_even(vector<int>& nums) {
        int n = nums.size();
         bool flag = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                for (int j = i + 1; j < n; j++) {
                    if ((nums[i] - nums[j]) % 2 == 0) {
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
            }
        }
        return flag;
    }

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2;

        bool is_even_possible = construct_even(nums2);
        bool is_odd_possible = construct_odd(nums2);
        return is_even_possible && is_odd_possible;
    }
};