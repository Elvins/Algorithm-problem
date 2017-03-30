/**
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        head->next = new ListNode(0);
        ListNode* ptr = head;
        ListNode* l1ptr = l1;
        ListNode* l2ptr = l2;
        while(l1ptr != NULL || l2ptr != NULL){
            ptr = ptr->next;
            int num1 = 0; 
            int num2 = 0;
            if(l1ptr != NULL){
                num1 = l1ptr->val;
                l1ptr = l1ptr->next;
            }
            if(l2ptr != NULL){
                num2 = l2ptr->val;
                l2ptr = l2ptr->next;
            }
            int sum = num1 + num2;
            ptr->val = ptr->val + sum;
            if(ptr->val >= 10){
                ptr->next = new ListNode(ptr->val/10);
                ptr->val = ptr->val % 10;
            }else{
                ptr->next = new ListNode(0);
            }
        }
        if(ptr->next->val == 0)
            ptr->next = NULL;
        return head->next;
    }
};