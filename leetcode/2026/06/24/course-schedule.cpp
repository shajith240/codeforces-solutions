/*
 * Problem: Course Schedule
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule/
 * Language: cpp
 * Topics: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * 
 * ── Problem ────────────────────────────────────────────
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1 . You are given an array prerequisites where prerequisites[i] = [a i , b i ] indicates that you must take course b i first if you want to take course a i .
 * • For example, the pair [0, 1] , indicates that to take course 0 you have to first take course 1 .
 * Return true if you can finish all courses. Otherwise, return false .
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 * Example 2:
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 * Constraints:
 * • 1 <= numCourses <= 2000
 * • 0 <= prerequisites.length <= 5000
 * • prerequisites[i].length == 2
 * • 0 <= a i , b i < numCourses
 * • All the pairs prerequisites[i] are unique .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * Hint 2: Topological Sort via DFS - A great tutorial explaining the basic concepts of Topological Sort.
 * Hint 3: Topological sort could also be done via BFS .
 * 
 */

class Solution {
public:
    

    bool topologicalSortCheck(unordered_map<int,vector<int>> &adj,int n , vector<int>& indegree){
        queue<int> que;
        
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
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
                    count++;
                    que.push(v);
                }
            }
        }

        if(count == n){
            //if this is true we just finish all the courses
            return true;
        }
         
         return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //first we are just creating a adjcency list for storing the graph we are getting
        unordered_map<int,vector<int>> adj;

        //this is an indegree vector to store the 
        vector<int> indegree(numCourses,0);
        

        //we are traversing in the prerequsites and just building the graph by following the pattern
        // b ---> a
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            //first do b then go to a
            adj[b].push_back(a);
            
            //as we just found out that we are reaching a from b so indegree of a should be increase
            indegree[a]++;
        }
        
        //this is where we are just checking that this graph is DAG or not using khan's algo
        return topologicalSortCheck(adj,numCourses,indegree);
    }
};