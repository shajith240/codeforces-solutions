/*
 * Problem: Left and Right Sum Differences
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/left-and-right-sum-differences/
 * Language: cpp
 * Topics: Array, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a 0-indexed integer array nums of size n .
 * Define two arrays leftSum and rightSum where:
 * • leftSum[i] is the sum of elements to the left of the index i in the array nums . If there is no such element, leftSum[i] = 0 .
 * • rightSum[i] is the sum of elements to the right of the index i in the array nums . If there is no such element, rightSum[i] = 0 .
 * Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]| .
 * Example 1:
 * Input: nums = [10,4,8,3]
 * Output: [15,1,11,22]
 * Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
 * The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
 * Example 2:
 * Input: nums = [1]
 * Output: [0]
 * Explanation: The array leftSum is [0] and the array rightSum is [0].
 * The array answer is [|0 - 0|] = [0].
 * Constraints:
 * • 1 <= nums.length <= 1000
 * • 1 <= nums[i] <= 10 5
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: For each index i, maintain two variables leftSum and rightSum.
 * Hint 2: Iterate on the range j: [0 … i - 1] and add nums[j] to the leftSum and similarly iterate on the range j: [i + 1 … nums.length - 1] and add nums[j] to the rightSum.
 * 
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer(n);
        int totalSum = 0;

        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];
        }
        int currentSum = 0;
        for(int i = 0 ; i < n ; i++){
            int leftSum = currentSum;
            currentSum += nums[i];
            int rightSum = totalSum - currentSum;

             answer[i] = abs(leftSum - rightSum);
        }
        return answer;
    }
};