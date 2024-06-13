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
        if (!head || !(head->next))
            return head;

        ListNode* unique = head;
        ListNode* duplicate = head;

        while (true)
        {
            while (duplicate->val == unique->val)
            {
                duplicate = duplicate->next;
                if (!duplicate)
                {
                    unique->next = nullptr;
                    return head;
                }
            }
            unique->next = duplicate;
            unique = unique->next;
        }
    }
};