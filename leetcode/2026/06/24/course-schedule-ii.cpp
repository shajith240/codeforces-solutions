/*
 * Problem: Course Schedule II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule-ii/
 * Language: cpp
 * Topics: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * 
 * ── Problem ────────────────────────────────────────────
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1 . You are given an array prerequisites where prerequisites[i] = [a i , b i ] indicates that you must take course b i first if you want to take course a i .
 * • For example, the pair [0, 1] , indicates that to take course 0 you have to first take course 1 .
 * Return the ordering of courses you should take to finish all courses . If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array .
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 * Example 2:
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
 * Example 3:
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 * Constraints:
 * • 1 <= numCourses <= 2000
 * • 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * • prerequisites[i].length == 2
 * • 0 <= a i , b i < numCourses
 * • a i != b i
 * • All the pairs [a i , b i ] are distinct .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * Hint 2: Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 * Hint 3: Topological sort could also be done via BFS .
 * 
 */

class Solution {
public:

    vector<int> topologicalSort(unordered_map<int,vector<int>>&adj,int n,vector<int> &indegree){
       
       queue<int> que;

       vector<int> result;

       int count = 0;

       for(int i = 0 ; i < n ; i++){
          if(indegree[i] == 0){
            result.push_back(i);
            count++;
            que.push(i);
          }
       }

       while(!que.empty()){
         
         int u = que.front();
         que.pop();

         for(int &v : adj[u]){
             indegree[v]--;

             if(indegree[v] == 0){
                result.push_back(v);
                count++;
                que.push(v);
             }
         }
       }

       if(count == n){
        return result;
       }

       return {};
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //first lets create the adj map for storing the graph we develop
        unordered_map<int,vector<int>> adj;

        //and then we have to create a vector to store the indegree of the each vertex
        vector<int> indegree(numCourses,0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            indegree[a]++;
        }

        return topologicalSort(adj,numCourses,indegree);
    }
};