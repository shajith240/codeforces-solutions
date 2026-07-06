/*
 * Problem: Remove Covered Intervals
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-covered-intervals/
 * Language: cpp
 * Topics: Array, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an array intervals where intervals[i] = [l i , r i ] represent the interval [l i , r i ) , remove all intervals that are covered by another interval in the list.
 * The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d .
 * Return the number of remaining intervals .
 * Example 1:
 * Input: intervals = [[1,4],[3,6],[2,8]]
 * Output: 2
 * Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 * Example 2:
 * Input: intervals = [[1,4],[2,3]]
 * Output: 1
 * Constraints:
 * • 1 <= intervals.length <= 1000
 * • intervals[i].length == 2
 * • 0 <= l i < r i <= 10 5
 * • All the given intervals are unique .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: How to check if an interval is covered by another?
 * Hint 2: Compare each interval to all others and check if it is covered by any interval.
 * 
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int count = 0;
        for (int i = 0; i < intervals.size(); i++) {
            bool isCovered = false;
            for (int j = 0; j < intervals.size(); j++) {

                 if(i==j){
                    continue;
                 }

                 if(intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]){
                    isCovered = true;
                    break;
                 }

            }

            if(isCovered){
                count++;
            }
        }

        return intervals.size() - count;
    }
};