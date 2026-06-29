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
        int count = 0;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
        int val = count-n;
        ListNode* node = head;
        ListNode* ptr = head;
        while(val!=0)
        {
            ptr = node;
            node = node->next;
            val--;
        }
        if (node==head)
        {
            node = node->next;
            ptr->next = NULL;
            return node;
        }
        ptr->next = node->next;
        node->next = NULL;
        return head;
    }
};
