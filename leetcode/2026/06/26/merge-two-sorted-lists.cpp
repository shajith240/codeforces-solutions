/*
 * Problem: Merge Two Sorted Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 * Language: cpp
 * Topics: Linked List, Recursion
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given the heads of two sorted linked lists list1 and list2 .
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list .
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 * Constraints:
 * • The number of nodes in both lists is in the range [0, 50] .
 * • -100 <= Node.val <= 100
 * • Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //we have to maintain two pointer's on both the linkedlist
        //and upon comparing both we add them to the new list ..and move the pointer's accordingly
        
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* result;
        if(list1->val < list2->val){
            result = list1;
            result->next = mergeTwoLists(list1->next,list2);
        }else{
            result = list2;
            result->next = mergeTwoLists(list1,list2->next);
        }
        
        return result;
    }
};