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

    ListNode* reverse(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* ahead = NULL;
        ListNode* prev = NULL;

        while(k>0){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
            k--;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        while(temp){
            ListNode* kth = temp;
            for(int i=0; i<k-1; i++){
                kth = kth->next;
                if(!kth){
                    prevnode->next = temp;
                    break;
                }
            }
            if(!kth) {
                break;
            }
            ListNode* newhead = kth->next;
            kth->next = NULL;
            reverse(temp, k);
            if(temp == head){
                head = kth;
            } else {
                prevnode->next = kth;
            }
            prevnode = temp;
            temp = newhead;
        }
        return head;
    }
};
