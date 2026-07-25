/*
 * Problem: Number of Unique XOR Triplets II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
 * Language: cpp
 * Topics: Array, Math, Bit Manipulation, Enumeration
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer array nums .
 * A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k .
 * Return the number of unique XOR triplet values from all possible triplets (i, j, k) .
 * Example 1:
 * Input: nums = [1,3]
 * Output: 2
 * Explanation:
 * The possible XOR triplet values are:
 * (0, 0, 0) &rarr; 1 XOR 1 XOR 1 = 1
 * (0, 0, 1) &rarr; 1 XOR 1 XOR 3 = 3
 * (0, 1, 1) &rarr; 1 XOR 3 XOR 3 = 1
 * (1, 1, 1) &rarr; 3 XOR 3 XOR 3 = 3
 * The unique XOR values are {1, 3} . Thus, the output is 2.
 * Example 2:
 * Input: nums = [6,7,8,9]
 * Output: 4
 * Explanation:
 * The possible XOR triplet values are {6, 7, 8, 9} . Thus, the output is 4.
 * Constraints:
 * • 1 <= nums.length <= 1500
 * • 1 <= nums[i] <= 1500
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: What is the maximum possible XOR value achievable by any triplet?
 * Hint 2: Let the maximum possible XOR value be stored in max_xor .
 * Hint 3: For each index i , consider all pairs of indices (j, k) such that i . For each such pair, compute the triplet XOR as nums[i] XOR nums[j] XOR nums[k] .
 * Hint 4: You can optimize the calculation by precomputing or reusing intermediate XOR results. For example, after fixing an index i , compute XORs of pairs (j, k) in O(n 2 ) time instead of checking all three indices independently.
 * Hint 5: Finally, count the number of unique XOR values obtained from all triplets.
 * 
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        //Store all Pair Xors
        unordered_set<int> s1;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        //Find triplet xors
        unordered_set<int> s2;
        for(int pairXor : s1) {
            for(int &num : nums) {
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
    }
};