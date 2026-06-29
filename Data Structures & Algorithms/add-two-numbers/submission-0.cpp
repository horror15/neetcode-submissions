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
        ListNode* ptr = NULL;
        ListNode* new_head = NULL;
        int carry = 0;
        int div = 0;
        while (l1!=NULL and l2!=NULL)
        {
            int val = l1->val+l2->val;
            val = val+carry;
            carry = val/10;
            div = val%10;
            ListNode* node = new ListNode(div);
            if (ptr == NULL){
                ptr = node;
                new_head = node;
            }
            else{
                ptr->next = node;
                ptr = ptr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1!=NULL){
            int val = l1->val + carry;
            carry = val/10;
            div = val%10;
            ListNode* node = new ListNode(div);
            ptr->next = node;
            ptr = ptr->next;
            l1 = l1->next;
        }
        while (l2!=NULL){
            int val = l2->val + carry;
            carry = val/10;
            div = val%10;
            ListNode* node = new ListNode(div);
            ptr->next = node;
            ptr = ptr->next;
            l2 = l2->next;
        }
        if (carry == 1){
            ListNode* node = new ListNode(1);
            ptr->next = node;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return new_head;
    }
};
