/*
 * Problem: Remove Duplicates from Sorted List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Language: cpp
 * Topics: Linked List
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once . Return the linked list sorted as well .
 * Example 1:
 * Input: head = [1,1,2]
 * Output: [1,2]
 * Example 2:
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 * Constraints:
 * • The number of nodes in the list is in the range [0, 300] .
 * • -100 <= Node.val <= 100
 * • The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        
        ListNode *first = head->next;
        ListNode *second = head;

        while(first){
            if(first->val == second->val){
                second->next = first->next;
                first = first->next;
            }else{
                first = first->next;
                second = second->next;
            }

        }
        return head;
    }
};