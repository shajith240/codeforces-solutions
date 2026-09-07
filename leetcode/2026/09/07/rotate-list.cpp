/*
 * Problem: Rotate List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotate-list/
 * Language: cpp
 * Topics: Linked List, Two Pointers
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the head of a linked list, rotate the list to the right by k places.
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * Example 2:
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * Constraints:
 * • The number of nodes in the list is in the range [0, 500] .
 * • -100 <= Node.val <= 100
 * • 0 <= k <= 2 * 10 9
 * 
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

       //in the linkedlist problems make sure to handle the edge case that is head = null
       if(head == nullptr || head->next == nullptr || k == 0){
        return head;
       }

       //first we need to find the lenght of the linkedlist
       int len = 1;

       ListNode *tail = head;
       while(tail->next != nullptr){
        tail = tail->next;
        len++;
       }

       k = k % len;
       
       if(k == 0){
        return head;
       }
       int size = len - k;
       
       ListNode *newtail = head;
       for(int i = 1 ; i < size ; i++){
          newtail = newtail->next;
       }
       
       ListNode *newhead = newtail->next;
       tail->next = head;
       newtail->next = nullptr;

       return newhead;
    }
};