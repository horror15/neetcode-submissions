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
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        typedef pair<int, ListNode*>p;
        priority_queue<p, vector<p>, greater<p>>pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()){
            pair<int, ListNode*> p = pq.top();
            tmp->next = p.second;
            tmp = tmp->next;
            pq.pop();
            if(tmp && tmp->next){
                pq.push({tmp->next->val, tmp->next});
            }
        }

        return dummy->next;
    }
};
