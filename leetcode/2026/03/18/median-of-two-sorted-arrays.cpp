/*
 * Problem: Median of Two Sorted Arrays
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * Language: cpp
 * Topics: Array, Binary Search, Divide and Conquer
 * 
 * ── Problem ────────────────────────────────────────────
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)) .
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * Constraints:
 * • nums1.length == m
 * • nums2.length == n
 * • 0 <= m <= 1000
 * • 0 <= n <= 1000
 * • 1 <= m + n <= 2000
 * • -10 6 <= nums1[i], nums2[i] <= 10 6
 * 
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){
           return findMedianSortedArrays(nums2,nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        //we are trying to make a partition in the array such that when we see the combined array it should be 
        //completly sorted 

        int l = 0;
        int r = m;

        while(l <= r){
            
            int Px = l + (r - l) / 2;
            int Py = ((m+n+1) / 2) - Px;

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];



            if(x1 <= x4 && x2 <= x3){
                if((m + n) % 2 == 1){
                    return max(x1,x2);
                }
                else{
                    return ((double)max(x1,x2) +  (double)min(x3,x4)) / 2.0;
                }
            }

            if(x1 > x4){
                r = Px - 1;
            }
            else{
                l = Px + 1;
            }
        }
        return -1;
    }
    
};