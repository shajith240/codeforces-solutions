/*
 * Problem: Majority Element II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/majority-element-ii/
 * Language: cpp
 * Topics: Array, Hash Table, Sorting, Counting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array of size n , find all elements that appear more than &lfloor; n/3 &rfloor; times.
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: [3]
 * Example 2:
 * Input: nums = [1]
 * Output: [1]
 * Example 3:
 * Input: nums = [1,2]
 * Output: [1,2]
 * Constraints:
 * • 1 <= nums.length <= 5 * 10 4
 * • -10 9 <= nums[i] <= 10 9
 * Follow up: Could you solve the problem in linear time and in O(1) space?
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Think about the possible number of elements that can appear more than ⌊ n/3 ⌋ times in the array.
 * Hint 2: It can be at most two. Why?
 * Hint 3: Consider using Boyer-Moore Voting Algorithm, which is efficient for finding elements that appear more than a certain threshold.
 * 
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            }
            if (nums[i] == candidate2) {
                count2++;
            }
        }

        vector<int> ans;
        if (candidate1 == candidate2) {
            ans.push_back(candidate1);
            return ans;
        }
        if (count1 > (n / 3)) {
            ans.push_back(candidate1);
        }
        if (count2 > (n / 3)) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};