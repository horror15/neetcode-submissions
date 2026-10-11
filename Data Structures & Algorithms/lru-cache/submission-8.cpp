class LRUCache {
    struct ListNode {
        ListNode* prev;
        ListNode* next;
        int key;
        int val;
        ListNode(int x, int y){
            key = x;
            val = y;
            prev = NULL;
            next = NULL;
        }
    };
public:
    unordered_map<int, ListNode*>mp;
    ListNode* dummyHead = new ListNode(-1,-1);
    ListNode* dummyTail = new ListNode(-1,-1);
    int cap=0;
    LRUCache(int capacity) {
        cap = capacity;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    void move(ListNode* node, ListNode* node1, ListNode* node2){
        if(node->prev == dummyHead) return;
        node1->next = node2;
        node2->prev = node1;
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }
    int get(int key) {
        if(mp.count(key)){
            move(mp[key], mp[key]->prev, mp[key]->next);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val = value;
            move(mp[key], mp[key]->prev, mp[key]->next);
        } else {
            if(mp.size()==cap){
                ListNode* node = dummyTail->prev->prev; 
                mp.erase(dummyTail->prev->key);
                delete dummyTail->prev;
                node->next = dummyTail;
                dummyTail->prev = node;
            }
            ListNode* node = new ListNode(key, value);
            mp[key] = node;
            node->next = dummyHead->next;
            node->prev = dummyHead;
            dummyHead->next->prev = node;
            dummyHead->next = node;
        }
    }
};
