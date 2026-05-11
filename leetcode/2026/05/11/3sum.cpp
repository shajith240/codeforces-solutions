/*
 * Problem: 3Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/3sum/
 * Language: cpp
 * Topics: Array, Two Pointers, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j , i != k , and j != k , and nums[i] + nums[j] + nums[k] == 0 .
 * Notice that the solution set must not contain duplicate triplets.
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * Constraints:
 * • 3 <= nums.length <= 3000
 * • -10 5 <= nums[i] <= 10 5
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: So, we essentially need to find three numbers x, y, and z such that they add up to the given value. If we fix one of the numbers say x, we are left with the two-sum problem at hand!
 * Hint 2: For the two-sum problem, if we fix one of the numbers, say x, we have to scan the entire array to find the next number y, which is value - x where value is the input parameter. Can we change our array somehow so that this search becomes faster?
 * Hint 3: The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?
 * 
 */

class Solution {
public:

   vector<vector<int>> result;
    
    void twosum(vector<int>nums,int target , int i , int j){
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }

            else{
                while(i < j && nums[i] == nums[i+1]){
                    i++;
                }
                while(i < j && nums[j] == nums[j-1]){
                    j--;
                }

                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        
        if(n < 3){
            return {};
        }

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i <  n ; i++){

            if( i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int n1 = nums[i];
            int target = -n1;
            twosum(nums,target,i+1,n - 1);
        }
        return result;
    }
};