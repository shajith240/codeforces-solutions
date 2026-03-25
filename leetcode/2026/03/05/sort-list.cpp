/*
 * Problem: Sort List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-list/
 * Language: cpp
 * Topics: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
 * 
 * ── Problem ────────────────────────────────────────────
 * Given the head of a linked list, return the list after sorting it in ascending order .
 * Example 1:
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * Example 2:
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * Example 3:
 * Input: head = []
 * Output: []
 * Constraints:
 * • The number of nodes in the list is in the range [0, 5 * 10 4 ] .
 * • -10 5 <= Node.val <= 10 5
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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

    
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;


        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);

        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1 -> val < list2 -> val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) {
            temp->next = list1;
        }
        else{
            temp->next = list2;
        }
        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left,right);
    }
    
};