/*
 * Problem: Minimum Score of a Path Between Two Cities
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 * Language: cpp
 * Topics: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a positive integer n representing n cities numbered from 1 to n . You are also given a 2D array roads where roads[i] = [a i , b i , distance i ] indicates that there is a bidirectional road between cities a i and b i with a distance equal to distance i . The cities graph is not necessarily connected.
 * The score of a path between two cities is defined as the minimum distance of a road in this path.
 * Return the minimum possible score of a path between cities 1 and n .
 * Note :
 * • A path is a sequence of roads between two cities.
 * • It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
 * • The test cases are generated such that there is at least one path between 1 and n .
 * Example 1:
 * Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
 * Output: 5
 * Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
 * It can be shown that no other path has less score.
 * Example 2:
 * Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
 * Output: 2
 * Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
 * Constraints:
 * • 2 <= n <= 10 5
 * • 1 <= roads.length <= 10 5
 * • roads[i].length == 3
 * • 1 <= a i , b i <= n
 * • a i != b i
 * • 1 <= distance i <= 10 4
 * • There are no repeated edges.
 * • There is at least one path between 1 and n .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Can you solve the problem if the whole graph is connected?
 * Hint 2: Notice that if the graph is connected, you can always use any edge of the graph in your path.
 * Hint 3: How to solve the general problem in a similar way? Remove all the nodes that are not connected to 1 and n, then apply the previous solution in the new graph.
 * 
 */

class Solution {
public:

    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int u, vector<bool>& visited, int &result) {
        
        visited[u] = true;
        
        for(auto &vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;
            
            result = min(result, c);
            
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : roads) {
            
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<bool> visited(n, false);
        int result = INT_MAX;
        dfs(adj, 1, visited, result);
        
        return result;
    }
};