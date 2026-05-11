/*
 * Problem: Min Stack
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/min-stack/
 * Language: cpp
 * Topics: Stack, Design
 * 
 * ── Problem ────────────────────────────────────────────
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Implement the MinStack class:
 * • MinStack() initializes the stack object.
 * • void push(int val) pushes the element val onto the stack.
 * • void pop() removes the element on the top of the stack.
 * • int top() gets the top element of the stack.
 * • int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 * Example 1:
 * Input
 * [&quot;MinStack&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;getMin&quot;,&quot;pop&quot;,&quot;top&quot;,&quot;getMin&quot;]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top(); // return 0
 * minStack.getMin(); // return -2
 * Constraints:
 * • -2 31 <= val <= 2 31 - 1
 * • Methods pop , top and getMin operations will always be called on non-empty stacks.
 * • At most 3 * 10 4 calls will be made to push , pop , top , and getMin .
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)
 * 
 */

class MinStack {
public:
    stack<pair<int,int>> s;

    MinStack() {

    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{
            int mini = min(val,s.top().second);
            s.push({val,mini});
        }
    }
    
    void pop() {
        return s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */