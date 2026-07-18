/*
 * Problem: Find Greatest Common Divisor of Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 * Language: cpp
 * Topics: Array, Math, Number Theory
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an integer array nums , return the greatest common divisor of the smallest number and largest number in nums .
 * The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
 * Example 1:
 * Input: nums = [2,5,6,9,10]
 * Output: 2
 * Explanation:
 * The smallest number in nums is 2.
 * The largest number in nums is 10.
 * The greatest common divisor of 2 and 10 is 2.
 * Example 2:
 * Input: nums = [7,5,6,8,3]
 * Output: 1
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 8.
 * The greatest common divisor of 3 and 8 is 1.
 * Example 3:
 * Input: nums = [3,3]
 * Output: 3
 * Explanation:
 * The smallest number in nums is 3.
 * The largest number in nums is 3.
 * The greatest common divisor of 3 and 3 is 3.
 * Constraints:
 * • 2 <= nums.length <= 1000
 * • 1 <= nums[i] <= 1000
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Find the minimum and maximum in one iteration. Let them be mn and mx.
 * Hint 2: Try all the numbers in the range [1, mn] and check the largest number which divides both of them.
 * 
 */

class Solution {
public:

    int gcd(int smallest,int largest){
        if(smallest == 0){
            return largest;
        }
        if(largest == 0){
            return smallest;
        }
        if(smallest == largest){
            return smallest;
        }
        if(smallest > largest){
            return gcd(smallest % largest , largest);
        }
        return gcd(smallest,largest % smallest);
    }

    
    int findGCD(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        return gcd(nums[0],nums[n-1]);
    }
};