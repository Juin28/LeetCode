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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;

        else if (l1 == nullptr)
            return l2;

        else if (l2 == nullptr)
            return l1;

        else
        {
            ListNode* p1 = l1;
            ListNode* p2 = l2;
            ListNode* p1_slow = nullptr;
            ListNode* p2_slow = nullptr;
            int carryIn = 0;
            
            while (p1 != nullptr && p2 != nullptr)
            {
                int sum = p1->val + p2->val + carryIn;
                carryIn = 0;

                if (sum >= 10)
                {
                    sum = sum % 10;
                    carryIn = 1;
                }

                p1->val = sum;
                p2->val = sum;
                p1_slow = p1;
                p2_slow = p2;
                p1 = p1->next;
                p2 = p2->next;
            }

            if (p1 == nullptr && p2 == nullptr)
            {
                if (carryIn != 0)
                    p1_slow->next = new ListNode(carryIn);
                return l1;
            }
            
            else if (p1 == nullptr)
            {
                while (p2 != nullptr)
                {
                    int sum = p2->val + carryIn;
                    carryIn = 0;

                    if (sum >= 10)
                    {
                        sum = sum % 10;
                        carryIn = 1;
                    }
                    
                    p2->val = sum;
                    p2_slow = p2;
                    p2 = p2->next;
                }

                if (carryIn != 0)
                    p2_slow->next = new ListNode(carryIn);
                return l2;
            }
            
            while (p1 != nullptr)
            {
                int sum = p1->val + carryIn;
                carryIn = 0;

                if (sum >= 10)
                {
                    sum = sum % 10;
                    carryIn = 1;
                }
                
                p1->val = sum;
                p1_slow = p1;
                p1 = p1->next;
            }
            if (carryIn != 0)
                p1_slow->next = new ListNode(carryIn);
            return l1;
        }
    }  
};