/*
 * Problem: Swap Nodes in Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Language: cpp
 * Topics: Linked List, Recursion
 * 
 * ── Problem ────────────────────────────────────────────
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list&#39;s nodes (i.e., only nodes themselves may be changed.)
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * Explanation:
 * Example 2:
 * Input: head = []
 * Output: []
 * Example 3:
 * Input: head = [1]
 * Output: [1]
 * Example 4:
 * Input: head = [1,2,3]
 * Output: [2,1,3]
 * Constraints:
 * • The number of nodes in the list is in the range [0, 100] .
 * • 0 <= Node.val <= 100
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
       ListNode *dummy = new ListNode(0);
       dummy->next = head;
       
       ListNode *prev = dummy;
       while(prev->next && prev->next->next){

        ListNode *first = prev->next;
        ListNode *second = first->next;
        ListNode *temp = second->next;

        //swap
        second->next = first;
        first->next = temp;
        prev->next = second;

        //next pair
        prev = first;
       }
       return dummy->next;
    }
};