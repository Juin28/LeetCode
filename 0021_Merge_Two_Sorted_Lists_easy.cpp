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
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode* new_head = nullptr;
        ListNode* temp = nullptr;

        if ( (node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr) )
        {
            return (node1 == nullptr) ? node2 : node1 ;
        }

        else if (list1 && list2)
        {
            if (node1->val <= node2->val)
            {
                new_head = node1;
                node1 = node1->next;
            }
            else
            {
                new_head = node2;
                node2 = node2->next;
            }

            temp = new_head;
            
            while(node1 && node2)
            {
                if (node1->val <= node2->val)
                {
                    temp->next = node1;
                    node1 = node1->next;
                }
                else
                {
                    temp->next = node2;
                    node2 = node2->next;
                }
                temp = temp->next;
            }
        }

        if (node1 || node2)
        {
            temp->next = (node1) ? node1 : node2;
        }

        return new_head;
    }
};