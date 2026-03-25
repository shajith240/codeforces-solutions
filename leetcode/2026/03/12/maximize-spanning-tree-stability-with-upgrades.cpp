/*
 * Problem: Maximize Spanning Tree Stability with Upgrades
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
 * Language: cpp
 * Topics: Binary Search, Greedy, Union-Find, Graph Theory, Minimum Spanning Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer n , representing n nodes numbered from 0 to n - 1 and a list of edges , where edges[i] = [u i , v i , s i , must i ] :
 * • u i and v i indicates an undirected edge between nodes u i and v i .
 * • s i is the strength of the edge.
 * • must i is an integer (0 or 1). If must i == 1 , the edge must be included in the spanning tree . These edges cannot be upgraded .
 * You are also given an integer k , the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with must i == 0 ) can be upgraded at most once.
 * The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
 * Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1 .
 * Note : A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected ) without forming any cycles, and uses exactly n - 1 edges.
 * Example 1:
 * Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1
 * Output: 2
 * Explanation:
 * • Edge [0,1] with strength = 2 must be included in the spanning tree.
 * • Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
 * • The resulting spanning tree includes these two edges with strengths 2 and 6.
 * • The minimum strength in the spanning tree is 2, which is the maximum possible stability.
 * Example 2:
 * Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2
 * Output: 6
 * Explanation:
 * • Since all edges are optional and up to k = 2 upgrades are allowed.
 * • Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
 * • The resulting spanning tree includes these two edges with strengths 8 and 6.
 * • The minimum strength in the tree is 6, which is the maximum possible stability.
 * Example 3:
 * Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
 * Output: -1
 * Explanation:
 * • All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.
 * Constraints:
 * • 2 <= n <= 10 5
 * • 1 <= edges.length <= 10 5
 * • edges[i] = [u i , v i , s i , must i ]
 * • 0 <= u i , v i < n
 * • u i != v i
 * • 1 <= s i <= 10 5
 * • must i is either 0 or 1 .
 * • 0 <= k <= n
 * • There are no duplicate edges.
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Sort the edges array in descending order of weights.
 * Hint 2: Try using binary search on ans .
 * Hint 3: Implement a chk function which first adds all the edges with must = 1 , and then adds the edges with must = 0 , using any remaining upgrades greedily.
 * Hint 4: Use a DSU with path compression and union by size/rank to maintain connected components.
 * Hint 5: Don't forget the case where you cannot form an MST because more than one component remains after processing all edges.
 * 
 */

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        return true;
    }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);

        vector<vector<int>> upgradeCandidates;

        for(auto &edge : edges) { //E
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) {
                if(s < mid) {
                    return false;
                }

                dsu.Union(u, v); //alpa
            } else {
                if(s >= mid) {
                    //no need to upgrade
                    dsu.Union(u, v);
                } else if(2*s >= mid) {
                    upgradeCandidates.push_back({u, v});
                }
            }
        }

        for(auto &edge : upgradeCandidates) { //O(E)
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) != dsu.find(v)) {
                if(k <= 0)
                    return false;
                
                dsu.Union(u, v);
                k--; //upgrade
            }
        }


        int root = dsu.find(0);
        for(int node = 1; node <= n-1; node++) { //O(n)
            if(dsu.find(node) != root)
                return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
         /*
            Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
            0 --- 1 --- 2 , parent = 0
            (2, 0)
            2 ka. parent kaun hai = 0
            0 ka parent kaun hai  = 0

        */

        DSU dsu(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) { //must be included in the spanning tree
                if(dsu.find(u) == dsu.find(v))
                    return -1;
                
                dsu.Union(u, v);
            }
        }


        int result = -1;
        int l = 1;
        int r = 2*1e5;

        //T.C : O(nlogn)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(n, edges, k, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid -1;
            }
        }

        return result;
    }
};