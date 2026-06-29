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
        unordered_map <Node*, Node*>mp;
        Node* tmp = head;
        Node* ptr = NULL;
        Node* new_head = NULL;
        while (tmp!=NULL)
        {
            Node* node = new Node(tmp->val);
            mp[tmp] = node;
            if (ptr == NULL)
            {
                ptr = node;
                new_head = node;
            }
            else{
                ptr->next = node;
                ptr = ptr->next;
            }
            tmp = tmp->next;
        }

        Node* ptr_1 = new_head;
        while (head!= NULL)
        {
            ptr_1->random = mp[head->random];
            ptr_1 = ptr_1->next;
            head = head->next;
        }
        return new_head;
    }
};
