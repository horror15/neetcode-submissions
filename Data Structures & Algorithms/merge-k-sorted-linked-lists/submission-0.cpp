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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair <int, ListNode*> p;
        priority_queue<p, vector<p>, greater<p>>pq;
        for (int i=0; i<lists.size(); i++) {
            pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        while (!pq.empty()){
            p item = pq.top();
            ListNode* node = item.second;
            ptr->next = node;
            node = node->next;
            ptr = ptr->next;
            pq.pop();
            if (node!=NULL){
                pq.push({node->val,node});
            }
        }
        return dummy->next;
    }
};
