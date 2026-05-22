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
    bool hasCycle(ListNode* head) {
        if(head == NULL) return false;
        ListNode* slow = head, *fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            if(slow->val == fast->val) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
