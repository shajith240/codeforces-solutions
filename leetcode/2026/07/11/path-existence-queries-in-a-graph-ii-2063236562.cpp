/*
 * Problem: Path Existence Queries in a Graph II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
 * Language: cpp
 * Topics: Array, Two Pointers, Binary Search, Dynamic Programming, Greedy, Bit Manipulation, Graph Theory, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1 .
 * You are also given an integer array nums of length n and an integer maxDiff .
 * An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff ).
 * You are also given a 2D integer array queries . For each queries[i] = [u i , v i ] , find the minimum distance between nodes u i and v i . If no path exists between the two nodes, return -1 for that query.
 * Return an array answer , where answer[i] is the result of the i th query.
 * Note: The edges between the nodes are unweighted.
 * Example 1:
 * Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]
 * Output: [1,1]
 * Explanation:
 * The resulting graph is:
 * Query
 * Shortest Path
 * Minimum Distance
 * [0, 3]
 * 0 &rarr; 3
 * 1
 * [2, 4]
 * 2 &rarr; 4
 * 1
 * Thus, the output is [1, 1] .
 * Example 2:
 * Input: n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]
 * Output: [1,2,-1,1]
 * Explanation:
 * The resulting graph is:
 * Query
 * Shortest Path
 * Minimum Distance
 * [0, 1]
 * 0 &rarr; 1
 * 1
 * [0, 2]
 * 0 &rarr; 1 &rarr; 2
 * 2
 * [2, 3]
 * None
 * -1
 * [4, 3]
 * 3 &rarr; 4
 * 1
 * Thus, the output is [1, 2, -1, 1] .
 * Example 3:
 * Input: n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]
 * Output: [0,-1,-1]
 * Explanation:
 * There are no edges between any two nodes because:
 * • Nodes 0 and 1: |nums[0] - nums[1]| = |3 - 6| = 3 > 1
 * • Nodes 0 and 2: |nums[0] - nums[2]| = |3 - 1| = 2 > 1
 * • Nodes 1 and 2: |nums[1] - nums[2]| = |6 - 1| = 5 > 1
 * Thus, no node can reach any other node, and the output is [0, -1, -1] .
 * Constraints:
 * • 1 <= n == nums.length <= 10 5
 * • 0 <= nums[i] <= 10 5
 * • 0 <= maxDiff <= 10 5
 * • 1 <= queries.length <= 10 5
 * • queries[i] == [u i , v i ]
 * • 0 <= u i , v i < n
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Sort the nodes according to nums[i] .
 * Hint 2: Can we use binary jumping?
 * Hint 3: Use binary jumping with a sparse table data structure.
 * 
 */

class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> ancestorTable;

    int customUpperBound(vector<pair<int, int>>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(arr[mid].first <= target) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //arr
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(begin(arr), end(arr));
        vector<int> nodeToIdx(n);
        for(int i = 0; i < n; i++) {
            int node = arr[i].second;
            nodeToIdx[node] = i;
        }

        rows = n;
        cols = log2(n)+1;
        ancestorTable.resize(rows, vector<int>(cols, 0));

        //Fill 0th column first
        for(int node = 0; node < n; node++) { //nlogn
            int farthestIdxOneHop = customUpperBound(arr, arr[node].first + maxDiff);
            ancestorTable[node][0] = farthestIdxOneHop;
        }

        //Fill remaining column
        for(int j = 1; j < cols; j++) { //logn
            for(int node = 0; node < n; node++) { //n
                ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
            }
        }

        vector<int> result;
        for(auto &query : queries) { //O(q)
            int u = query[0];
            int v = query[1];

            int a = nodeToIdx[u];
            int b = nodeToIdx[v];
            if(a == b) {
                result.push_back(0);
                continue;
            }

            if(a > b) {
                swap(a, b);
            }

            int curr  = a;
            int jumps = 0;

            for(int j = cols-1; j >= 0; j--) { //log(n)
                if(ancestorTable[curr][j] < b) {
                    curr = ancestorTable[curr][j];
                    jumps += (1 << j); //pow(2, j)
                }
            }

            if(ancestorTable[curr][0] >= b) {
                result.push_back(jumps+1);
            } else {
                result.push_back(-1);
            }
            
        }

        return result;

    }
};