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
        int size = 0;
        ListNode* tmp = head;

        while (tmp)
        {
            size++;
            tmp = tmp->next;
        }

        if (size == n)
            head = head->next;

        else
        {
            int cur = 1;
            int target = size - n;
            tmp = head;

            while (cur < target)
            {
                tmp = tmp->next;
                cur++;
            }

            tmp->next = tmp->next->next;

        }

        return head;

    }
};
