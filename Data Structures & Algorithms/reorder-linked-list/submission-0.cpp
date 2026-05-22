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
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {        
        ListNode* prev = NULL, *curr = head, *next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        
        ListNode* mid = getMidNode(head);
        ListNode* tempNode = mid->next;
        mid->next = NULL; // Break the list 

        ListNode* head1 = head;
        ListNode* head2 = reverseList(tempNode);

        // Merge both lists 
        while(head1 != NULL && head2 != NULL) {
            ListNode* temp = head1;
            head1 = head1->next;
            temp->next = head2;
            
            temp = head2;
            head2 = head2->next;
            temp->next = head1;
        }
    }
};
