/*
 * Problem: Task Scheduler
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/task-scheduler/
 * Language: cpp
 * Topics: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an array of CPU tasks , each labeled with a letter from A to Z, and a number n . Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there&#39;s a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
 * Return the minimum number of CPU intervals required to complete all tasks.
 * Example 1:
 * Input: tasks = [&quot;A&quot;,&quot;A&quot;,&quot;A&quot;,&quot;B&quot;,&quot;B&quot;,&quot;B&quot;], n = 2
 * Output: 8
 * Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
 * After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3 rd interval, neither A nor B can be done, so you idle. By the 4 th interval, you can do A again as 2 intervals have passed.
 * Example 2:
 * Input: tasks = [&quot;A&quot;,&quot;C&quot;,&quot;A&quot;,&quot;B&quot;,&quot;D&quot;,&quot;B&quot;], n = 1
 * Output: 6
 * Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
 * With a cooling interval of 1, you can repeat a task after just one other task.
 * Example 3:
 * Input: tasks = [&quot;A&quot;,&quot;A&quot;,&quot;A&quot;, &quot;B&quot;,&quot;B&quot;,&quot;B&quot;], n = 3
 * Output: 10
 * Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
 * There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
 * Constraints:
 * • 1 <= tasks.length <= 10 4
 * • tasks[i] is an uppercase English letter.
 * • 0 <= n <= 100
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: There are many different solutions for this problem, including a greedy algorithm.
 * Hint 2: For every cycle, find the most frequent letter that can be placed in this cycle. After placing, decrease the frequency of that letter by one.
 * Hint 3: Use Priority Queue.
 * 
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);

        for(char &ch : tasks){
            mp[ch - 'A']++;
        }

        int time = 0;

        priority_queue<int> pq;

        for(int i = 0 ; i < 26 ; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }


        while(!pq.empty()){

            vector<int>temp;
            for(int i = 1 ; i <= n+1 ; i++){
               
               if(!pq.empty()){
                  int freq = pq.top();
                  pq.pop();
                  freq--;
                  temp.push_back(freq);
               }
            }

            for(int &f : temp){
                if(f > 0){
                  pq.push(f);
                }
            }
            
            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }

        }

        return time;   
    }
};