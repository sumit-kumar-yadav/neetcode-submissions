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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        int count = 0;
        
        while(count < n && temp1 != NULL) {
            count++;
            temp1 = temp1->next;
        }
        if(temp1 == NULL) return head->next;

        ListNode* temp2 = head;
        while(temp1->next != NULL) {
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
