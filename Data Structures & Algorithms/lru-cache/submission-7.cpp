struct ListNode{
    int value;
    int key;
    ListNode* next;
    ListNode* prev;
    ListNode (int val, int key) : value(val), key(key), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    unordered_map<int, ListNode*>mp;
    int cap;
    int length = 0;
    ListNode* head;
    ListNode* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(0,0);
        tail = new ListNode(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(ListNode* node){
        ListNode* tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
    }

    void remove(ListNode* node){
        ListNode* tmp1 = node->next;
        ListNode* tmp2 = node->prev;
        tmp2->next = tmp1;
        tmp1->prev = tmp2;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()){
            mp[key]->value = value;
            remove(mp[key]);
            insert(mp[key]);
        }
        else if (cap == length){
            ListNode* node = tail->prev;
            mp.erase(node->key);
            remove(node);
            delete node;
            ListNode* node1 = new ListNode(value, key);
            insert(node1);
            mp[key] = node1;
        }
        else {
            ListNode* node = new ListNode(value,key);
            insert (node);
            mp[key] = node;
            length+=1;
        }
    }
};
