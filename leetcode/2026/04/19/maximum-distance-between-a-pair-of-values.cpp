/*
 * Problem: Maximum Distance Between a Pair of Values
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 * Language: cpp
 * Topics: Array, Two Pointers, Binary Search
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given two non-increasing 0-indexed integer arrays nums1 ​​​​​​ and nums2 ​​​​​​.
 * A pair of indices (i, j) , where 0 <= i < nums1.length and 0 <= j < nums2.length , is valid if both i <= j and nums1[i] <= nums2[j] . The distance of the pair is j - i ​​​​.
 * Return the maximum distance of any valid pair (i, j) . If there are no valid pairs, return 0 .
 * An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length .
 * Example 1:
 * Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
 * Output: 2
 * Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
 * The maximum distance is 2 with pair (2,4).
 * Example 2:
 * Input: nums1 = [2,2,2], nums2 = [10,10,1]
 * Output: 1
 * Explanation: The valid pairs are (0,0), (0,1), and (1,1).
 * The maximum distance is 1 with pair (0,1).
 * Example 3:
 * Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
 * Output: 2
 * Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
 * The maximum distance is 2 with pair (2,4).
 * Constraints:
 * • 1 <= nums1.length, nums2.length <= 10 5
 * • 1 <= nums1[i], nums2[j] <= 10 5
 * • Both nums1 and nums2 are non-increasing .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Since both arrays are sorted in a non-increasing way this means that for each value in the first array. We can find the farthest value smaller than it using binary search.
 * Hint 2: There is another solution using a two pointers approach since the first array is non-increasing the farthest j such that nums2[j] ≥ nums1[i] is at least as far as the farthest j such that nums2[j] ≥ nums1[i-1]
 * 
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // what are the step's we have to follow?
        // 1.take input
        // 2.find the distance between the position not the elements and store
        // it in a max dist 3.first we have to find the valid pair for this

        // heare is the catch we want the min index from the nums1 and index
        // from the nums my approch is that by doin inary search on both taht
        // array's and figure out is taht pair valid an store it in the maxdist
        int max = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i;
        for (i = 0; i < n1; i++) {
            int low = i;
            int high = n2 - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (nums2[mid] >= nums1[i]) {
                    if (mid - i > max) {
                        max = mid - i;
                    }
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return max;
    }
};