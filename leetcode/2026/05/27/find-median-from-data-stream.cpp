/*
 * Problem: Find Median from Data Stream
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 * Language: cpp
 * Topics: Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
 * 
 * ── Problem ────────────────────────────────────────────
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
 * • For example, for arr = [2,3,4] , the median is 3 .
 * • For example, for arr = [2,3] , the median is (2 + 3) / 2 = 2.5 .
 * Implement the MedianFinder class:
 * • MedianFinder() initializes the MedianFinder object.
 * • void addNum(int num) adds the integer num from the data stream to the data structure.
 * • double findMedian() returns the median of all elements so far. Answers within 10 -5 of the actual answer will be accepted.
 * Example 1:
 * Input
 * [&quot;MedianFinder&quot;, &quot;addNum&quot;, &quot;addNum&quot;, &quot;findMedian&quot;, &quot;addNum&quot;, &quot;findMedian&quot;]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1); // arr = [1]
 * medianFinder.addNum(2); // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3); // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 * Constraints:
 * • -10 5 <= num <= 10 5
 * • There will be at least one element in the data structure before calling findMedian .
 * • At most 5 * 10 4 calls will be made to addNum and findMedian .
 * Follow up:
 * • If all integer numbers from the stream are in the range [0, 100] , how would you optimize your solution?
 * • If 99% of all integer numbers from the stream are in the range [0, 100] , how would you optimize your solution?
 * 
 */

class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>,greater<int>> right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }


    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()){
            return (left_max_heap.top() + right_min_heap.top()) / 2.0;
        }else{
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */