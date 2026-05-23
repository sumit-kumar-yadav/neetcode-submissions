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

auto comp = [](ListNode* node1, ListNode* node2) {
    return node1->val > node2->val;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        if(k == 1) return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minPq(comp);
        for(int i = 0; i < k; i++) minPq.push(lists[i]);

        ListNode* head = NULL, *tail = NULL;
        while(!minPq.empty()) {
            ListNode* top = minPq.top();
            minPq.pop();

            if(head == NULL) head = top;
            else tail->next = top;
            tail = top;
            
            if(top->next != NULL) minPq.push(top->next);
            else top->next = NULL;
        }
        return head;
    }
};
