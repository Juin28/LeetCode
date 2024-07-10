/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        unordered_map <Node*, Node*> get_add;

        Node* temp = head;
        while (temp)
        {
            get_add[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            get_add[temp]->next = get_add[temp->next];
            get_add[temp]->random = get_add[temp->random];
            temp = temp->next;
        }

        return get_add[head];
    }
};