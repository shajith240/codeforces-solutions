/*
 * Problem: Sorted GCD Pair Queries
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/sorted-gcd-pair-queries/
 * Language: cpp
 * Topics: Array, Hash Table, Math, Binary Search, Combinatorics, Counting, Number Theory, Prefix Sum
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer array nums of length n and an integer array queries .
 * Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]) , where 0 <= i < j < n , and then sorting these values in ascending order.
 * For each query queries[i] , you need to find the element at index queries[i] in gcdPairs .
 * Return an integer array answer , where answer[i] is the value at gcdPairs[queries[i]] for each query.
 * The term gcd(a, b) denotes the greatest common divisor of a and b .
 * Example 1:
 * Input: nums = [2,3,4], queries = [0,2,2]
 * Output: [1,2,2]
 * Explanation:
 * gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1] .
 * After sorting in ascending order, gcdPairs = [1, 1, 2] .
 * So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2] .
 * Example 2:
 * Input: nums = [4,4,2,1], queries = [5,3,1,0]
 * Output: [4,2,1,1]
 * Explanation:
 * gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4] .
 * Example 3:
 * Input: nums = [2,2], queries = [0,0]
 * Output: [2,2]
 * Explanation:
 * gcdPairs = [2] .
 * Constraints:
 * • 2 <= n == nums.length <= 10 5
 * • 1 <= nums[i] <= 5 * 10 4
 * • 1 <= queries.length <= 10 5
 * • 0 <= queries[i] < n * (n - 1) / 2
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Try counting the number of pairs that have a GCD of g</code.
 * Hint 2: Use inclusion-exclusion.
 * 
 */

class Solution {
public:
    

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        

        //generating all the pair is impossible so the step's i will follow are
        //1.generate the freq map of numbers
        //2.for every g i will countdivisible[g] by summing the freq of it's multiples
        //3.compute pairs divisible by pairDivisibleby[g] = c(countdivisible[g],2);
        //4.travese g from max to 1 to obtain the larger multiples to obtain exact[g]
        //5.build a prefix sum over exact[g]


        int maxVal = 0;

        // Find maximum value in nums
        for (int x : nums)
            maxVal = max(maxVal, x);

        // freq[i] = how many times value i appears
        vector<long long> freq(maxVal + 1, 0);

        for (int x : nums)
            freq[x]++;

        // exactGcd[g] = number of pairs having gcd exactly g
        vector<long long> exactGcd(maxVal + 1, 0);

        // Calculate from larger gcd to smaller gcd
        for (int g = maxVal; g >= 1; g--) {

            long long cnt = 0;

            // Count numbers divisible by g
            for (int multiple = g; multiple <= maxVal; multiple += g)
                cnt += freq[multiple];

            // Total pairs divisible by g
            long long pairs = cnt * (cnt - 1) / 2;

            // Remove pairs whose gcd is a larger multiple of g
            for (int multiple = 2 * g; multiple <= maxVal; multiple += g)
                pairs -= exactGcd[multiple];

            exactGcd[g] = pairs;
        }

        // prefix[g] = number of pairs having gcd <= g
        vector<long long> prefix(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++)
            prefix[g] = prefix[g - 1] + exactGcd[g];

        vector<int> answer;

        for (long long k : queries) {

            // Find first gcd whose prefix count is greater than k
            int gcdValue = lower_bound(prefix.begin(), prefix.end(), k + 1) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};