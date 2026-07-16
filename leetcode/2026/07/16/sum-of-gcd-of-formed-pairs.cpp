/*
 * Problem: Sum of GCD of Formed Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 * Language: cpp
 * Topics: Array, Math, Two Pointers, Sorting, Simulation, Number Theory
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer array nums of length n .
 * Construct an array prefixGcd where for each index i :
 * • Let mx i = max(nums[0], nums[1], ..., nums[i]) .
 * • prefixGcd[i] = gcd(nums[i], mx i ) .
 * After constructing prefixGcd :
 * • Sort prefixGcd in non-decreasing order.
 * • Form pairs by taking the smallest unpaired element and the largest unpaired element.
 * • Repeat this process until no more pairs can be formed.
 * • For each formed pair, compute the gcd of the two elements.
 * • If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
 * Return an integer denoting the sum of the GCD values of all formed pairs.
 * The term gcd(a, b) denotes the greatest common divisor of a and b .
 * Example 1:
 * Input: nums = [2,6,4]
 * Output: 2
 * Explanation:
 * Construct prefixGcd :
 * i
 * nums[i]
 * mx i
 * prefixGcd[i]
 * 0
 * 2
 * 2
 * 2
 * 1
 * 6
 * 6
 * 6
 * 2
 * 4
 * 6
 * 2
 * prefixGcd = [2, 6, 2] . After sorting, it forms [2, 2, 6] .
 * Pair the smallest and largest elements: gcd(2, 6) = 2 . The remaining middle element 2 is ignored. Thus, the sum is 2.
 * Example 2:
 * Input: nums = [3,6,2,8]
 * Output: 5
 * Explanation:
 * Construct prefixGcd :
 * i
 * nums[i]
 * mx i
 * prefixGcd[i]
 * 0
 * 3
 * 3
 * 3
 * 1
 * 6
 * 6
 * 6
 * 2
 * 2
 * 6
 * 2
 * 3
 * 8
 * 8
 * 8
 * prefixGcd = [3, 6, 2, 8] . After sorting, it forms [2, 3, 6, 8] .
 * Form pairs: gcd(2, 8) = 2 and gcd(3, 6) = 3 . Thus, the sum is 2 + 3 = 5 .
 * Constraints:
 * • 1 <= n == nums.length <= 10 5
 * • 1 <= nums[i] <= 10 ​​​​​​​9
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Maintain a running prefix maximum mx i while iterating nums to compute prefixGcd[i] = gcd(nums[i], mx i ) .
 * Hint 2: Sort prefixGcd in non-decreasing order.
 * Hint 3: Form pairs by combining smallest unpaired and largest unpaired elements.
 * Hint 4: Compute gcd for each pair and sum them; ignore middle element if n is odd.
 * 
 */

class Solution {
public:
    
    int gcd(int a ,int b){
        if(a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        if(a == b){
            return a;
        }
        if(a > b){
            return gcd(a % b,b);
        }
        
        return gcd(a,b % a);

    }


    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>maxArray(n);
        
        int currentMax = nums[0];
        maxArray[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
           if(nums[i] > currentMax){
             currentMax = nums[i];
           }
           maxArray[i] = currentMax;
        }

        vector<int>prefixGcd(n);

        for(int i = 0 ; i < n ; i++){
            prefixGcd[i] = gcd(nums[i],maxArray[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int i = 0,j = n - 1;
        long long sum = 0;
        while(j > i){
            sum += gcd(prefixGcd[i] , prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};