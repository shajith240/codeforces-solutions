/*
 * Problem: Filter Occupied Intervals
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/filter-occupied-intervals/
 * Language: cpp
 * Topics: 
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a 2D integer array occupiedIntervals , where occupiedIntervals[i] = [start i , end i ] represents a time interval during which you are occupied. Each interval starts at start i and ends at end i , inclusive . These intervals may overlap .
 * You are also given two integers freeStart and freeEnd , which define a free time interval from freeStart to freeEnd , inclusive.
 * Your task is to merge all occupied intervals that overlap or touch, then remove all integer points in the free interval from the merged occupied intervals.
 * Two intervals touch if the second interval starts immediately after the first one ends. For example, [1, 1] and [2, 2] touch and should be merged into [1, 2] .
 * Return the remaining occupied intervals in sorted order. The returned intervals must be non-overlapping and must contain the minimum number of intervals possible. If there are no remaining occupied points, return an empty list.
 * Example 1:
 * Input: occupiedIntervals = [[2,6],[4,8],[10,10],[10,12],[14,16]], freeStart = 7, freeEnd = 11
 * Output: [[2,6],[12,12],[14,16]]
 * Explanation:
 * • After merging, the occupied intervals are [2, 8] , [10, 12] , and [14, 16] .
 * • Excluding the free interval [7, 11] results in [2, 6] , [12, 12] , and [14, 16] .
 * Example 2:
 * Input: occupiedIntervals = [[1,5],[2,3]], freeStart = 3, freeEnd = 8
 * Output: [[1,2]]
 * Explanation:
 * • After merging, the occupied interval is [1, 5] .
 * • Excluding the free interval [3, 8] results in [1, 2] .
 * Constraints:
 * • 1 <= occupiedIntervals.length <= 5 * 10 4
 * • occupiedIntervals[i].length == 2
 * • 1 <= start i <= end i <= 10 9
 * • 1 <= freeStart <= freeEnd <= 10 9
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Sort the occupied intervals by start time.
 * Hint 2: While merging, two intervals should be combined if the next interval starts at most one point after the current interval ends.
 * Hint 3: After merging, remove [freeStart, freeEnd] from each merged interval independently.
 * Hint 4: An interval may disappear completely, shrink on one side, remain unchanged, or split into two intervals.
 * 
 */

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        vector<vector<int>> m;

        for(auto& v : occupiedIntervals){
            if(m.empty() || m.back()[1] + 1 < v[0]){
                m.push_back(v);
            }
            else{
                m.back()[1] = max(m.back()[1],v[1]);
            }
        }


        vector<vector<int>> ans;

        for(auto&v : m ){
            if(v[0] < freeStart){
                ans.push_back({v[0],min(v[1],freeStart - 1)});
            }
            if(v[1] > freeEnd){
                ans.push_back({max(v[0],freeEnd + 1),v[1]});
            }
        }

        return ans;
    }
};