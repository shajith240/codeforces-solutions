/*
 * Problem: Remove Methods From Project
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-methods-from-project/
 * Language: cpp
 * Topics: Depth-First Search, Breadth-First Search, Graph Theory
 * 
 * ── Problem ────────────────────────────────────────────
 * You are maintaining a project that has n methods numbered from 0 to n - 1 .
 * You are given two integers n and k , and a 2D integer array invocations , where invocations[i] = [a i , b i ] indicates that method a i invokes method b i .
 * There is a known bug in method k . Method k , along with any method invoked by it, either directly or indirectly , are considered suspicious and we aim to remove them.
 * A group of methods can only be removed if no method outside the group invokes any methods within it.
 * Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order . If it is not possible to remove all the suspicious methods, none should be removed.
 * Example 1:
 * Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
 * Output: [0,1,2,3]
 * Explanation:
 * Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.
 * Example 2:
 * Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
 * Output: [3,4]
 * Explanation:
 * Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.
 * Example 3:
 * Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
 * Output: []
 * Explanation:
 * All methods are suspicious. We can remove them.
 * Constraints:
 * • 1 <= n <= 10 5
 * • 0 <= k <= n - 1
 * • 0 <= invocations.length <= 2 * 10 5
 * • invocations[i] == [a i , b i ]
 * • 0 <= a i , b i <= n - 1
 * • a i != b i
 * • invocations[i] != invocations[j]
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Use DFS from node k .
 * Hint 2: Mark all the nodes visited from node k , and then check if they can be visited from the other nodes.
 * 
 */

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int>sus(n,0);
        sus[k]=1;
        queue<int>q;
        q.push(k);
        int total=1;
        map<int,int>mp;
        mp[k]=1;
         vector<int>ans;
        while(!q.empty()){
            auto temp =q.front();
            q.pop();
            for(auto &it:adj[temp]){
                if(!sus[it]){
                    total++;
                    mp[it]=1;
                    sus[it]=1;
                    q.push(it);
                }
            }
        }
        if(total==n){
            return {};
        }
         for(int i=0;i<invocations.size();i++){
            adj[invocations[i][1]].push_back(invocations[i][0]);
        }
        int possible=0;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                for(auto &it:adj[i]){
                    if(mp[it]==1){
                        sus[i]=1;
                        possible=1;
                    }
                }
            }
            if(possible){
                break;
            }
        }
        
        if(possible){
        for(int i=0;i<n;i++){
                ans.push_back(i);
        }
        return ans;
        }
        for(int i=0;i<n;i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};