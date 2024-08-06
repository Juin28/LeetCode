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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2)
            return nullptr;
        else if (!list1)
            return list2;
        else if (!list2)
            return list1;

        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode* newHead = nullptr;

        if (node1->val > node2->val)
        {
            newHead = node2;
            node2 = node2->next;
        }
        else
        {
            newHead = node1;
            node1 = node1->next;
        }

        ListNode* newNode = newHead;

        while (node1 && node2)
        {
            if (node1->val > node2->val)
            {
                newNode->next = node2;
                node2 = node2->next;
            }
            else
            {
                newNode->next = node1;
                node1 = node1->next;
            }
            newNode = newNode->next;
        }

        if (node1 || node2)
            newNode->next = node1 ? node1 : node2;

        return newHead;

    }
};