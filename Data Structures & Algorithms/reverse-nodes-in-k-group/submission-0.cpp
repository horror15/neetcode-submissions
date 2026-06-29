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

    ListNode* kth(ListNode* node, int k){
        while(node && k!=1){
            node = node->next;
            k-=1;
        }
        return node;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* last = NULL;
        while (tmp){
            ListNode* k_node = kth(tmp, k);
            if(!k_node){
                last->next = tmp;
                break;
            }
            ListNode* g_next = k_node->next;
            k_node->next = NULL;
            ListNode* node = reverse(tmp);
            if (tmp == head){
                head = k_node;
            } else {
                last->next = node;
            }
            last = tmp;
            tmp = g_next;
        }
        return head;
    }
};
