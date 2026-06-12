/*
 * Problem: Number of Ways to Assign Edge Weights I
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
 * Language: cpp
 * Topics: Math, Tree, Depth-First Search
 * 
 * ── Problem ────────────────────────────────────────────
 * There is an undirected tree with n nodes labeled from 1 to n , rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1 , where edges[i] = [u i , v i ] indicates that there is an edge between nodes u i and v i .
 * Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2 .
 * The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
 * Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd .
 * Since the answer may be large, return it modulo 10 9 + 7 .
 * Note: Ignore all edges not in the path from node 1 to x .
 * Example 1:
 * Input: edges = [[1,2]]
 * Output: 1
 * Explanation:
 * • The path from Node 1 to Node 2 consists of one edge ( 1 &rarr; 2 ).
 * • Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 * Example 2:
 * Input: edges = [[1,2],[1,3],[3,4],[3,5]]
 * Output: 2
 * Explanation:
 * • The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
 * • For example, the path from Node 1 to Node 4 consists of two edges ( 1 &rarr; 3 and 3 &rarr; 4 ).
 * • Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
 * Constraints:
 * • 2 <= n <= 10 5
 * • edges.length == n - 1
 * • edges[i] == [u i , v i ]
 * • 1 <= u i , v i <= n
 * • edges represents a valid tree.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Depth‑First Search (DFS) to compute the depth of each node from the root.
 * Hint 2: Find the maximum depth, max_depth .
 * Hint 3: The number of 2 s doesn’t affect parity; we only need an odd number of 1 s along the path.
 * Hint 4: The number of ways to choose an odd count of 1s among max_depth edges is 2^(max_depth-1) .
 * 
 */

class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {

        int depth = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, neighbor, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }
};