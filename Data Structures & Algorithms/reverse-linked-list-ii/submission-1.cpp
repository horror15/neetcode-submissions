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
    ListNode* reverse(ListNode* head, int right){
            if (right==1){
                return head;
            }
        ListNode* new_head = reverse(head->next, right-1);
        ListNode* tmp = head->next->next;
        head->next->next = head;
        head->next = tmp;  
        return new_head;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left==right){
            return head;
        }
        ListNode* ptr = NULL;
        ListNode* tmp = head;
        while(left!=1){
            ptr = tmp;
            tmp = tmp->next;
            left-=1;
            right-=1;
        }
        ListNode* new_head = reverse(tmp, right);
        if (ptr == NULL){
            return new_head;
        }
        ptr->next = new_head;
        return head;
    }
};