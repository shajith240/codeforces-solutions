/*
 * Problem: Longest Consecutive Sequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * Language: cpp
 * Topics: Array, Hash Table, Union-Find
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an unsorted array of integers nums , return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 * Example 1:
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4] . Therefore its length is 4.
 * Example 2:
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * Example 3:
 * Input: nums = [1,0,1,2]
 * Output: 3
 * Constraints:
 * • 0 <= nums.length <= 10 5
 * • -10 9 <= nums[i] <= 10 9
 * 
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for(int i = 1; i < nums.size(); i++) {

            // Skip duplicates
            if(nums[i] == nums[i - 1]) {
                continue;
            }

            // Consecutive element
            if(nums[i] == nums[i - 1] + 1) {
                current++;
            }

            // Sequence broken
            else {
                longest = max(longest, current);
                current = 1;
            }
        }

        longest = max(longest, current);

        return longest;
    }
};