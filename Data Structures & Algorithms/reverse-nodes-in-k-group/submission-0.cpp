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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0 || k == 1) return head;

        int count = 0;

        ListNode* tail = head, *newHead = NULL, *newTail = NULL;
        while(tail != NULL) {
            count++;
            if(count == k) {
                // Disconnect k LL 
                ListNode* temp = tail->next;
                tail->next = NULL;
                if(newTail != NULL) newTail->next = NULL;
                
                ListNode* smallHead = reverseLL(head);
                if(newHead == NULL) newHead = smallHead;
                
                // Connect reveresed k LL 
                if(newTail != NULL) newTail->next = smallHead;
                head->next = temp;

                newTail = head;
                head = temp;
                tail = head;
                count = 0;
            }
            else tail = tail->next;
        }
        return newHead;
    }
};
