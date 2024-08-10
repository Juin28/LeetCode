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
        ListNode* tmp = head;
        while(tmp)
        {
            if (tmp->next && tmp->next->val == 100001)
                return true;
            tmp->val = 100001;
            tmp = tmp->next;
        }
        return false;
    }
};
