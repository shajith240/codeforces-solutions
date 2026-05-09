/*
 * Problem: Top K Frequent Elements
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 * Language: cpp
 * Topics: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array nums and an integer k , return the k most frequent elements . You may return the answer in any order .
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * Example 3:
 * Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
 * Output: [1,2]
 * Constraints:
 * • 1 <= nums.length <= 10 5
 * • -10 4 <= nums[i] <= 10 4
 * • k is in the range [1, the number of unique elements in the array] .
 * • It is guaranteed that the answer is unique .
 * Follow up: Your algorithm&#39;s time complexity must be better than O(n log n) , where n is the array&#39;s size.
 * 
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> freq;

        for(auto it : mp){
            freq.push_back({it.second,it.first});
        }

        sort(freq.rbegin(),freq.rend());
        
        vector<int> ans;

        for(int i = 0 ; i < k ; i++){
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};