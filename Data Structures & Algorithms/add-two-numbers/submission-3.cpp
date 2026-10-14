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
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val+l2->val+carry;
            int rem = sum%10;
            ListNode* node = new ListNode(rem);
            tmp->next = node;
            tmp = tmp->next;
            if(sum>9){
                carry = sum/10;
            } else carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                int sum = l1->val+carry;
                int rem = sum%10;
                ListNode* node = new ListNode(rem);
                tmp->next = node;
                tmp = tmp->next;
                if(sum>9){
                    carry = sum/10;
                } else carry = 0;
                l1 = l1->next;
            }
        }
        if(l2){
            while(l2){
                int sum = l2->val+carry;
                int rem = sum%10;
                ListNode* node = new ListNode(rem);
                tmp->next = node;
                tmp = tmp->next;
                if(sum>9){
                    carry = sum/10;
                } else {
                    carry = 0;
                }
                l2 = l2->next;
            }
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            tmp->next = node;
            tmp = tmp->next;
        }
        tmp->next = NULL;
        return dummy->next;
    }
};
