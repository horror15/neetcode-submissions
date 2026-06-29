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
    ListNode* head = NULL;
    ListNode* tail = NULL;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    void insert(int value, int key){
        ListNode* node = new ListNode(value, key);
        node->value = value;
        node->key = key;
        node->next = head;
        node->prev = NULL; 
        if (head == NULL && tail == NULL){
            head = node;
            tail = node;
        }
        else{
            head->prev = node;
            head = head->prev;
        }
        mp[key] = node;        
    }

    void move(int key){
        ListNode* tmp1 = mp[key]->next;
        ListNode* tmp2 = mp[key]->prev;
        if (tmp1 == NULL){
            tail = tmp2;
            tmp2->next = NULL;
        } else{
            tmp2->next = tmp1;
            tmp1->prev= tmp2;
        }

        mp[key]->next = head;
        mp[key]->prev = NULL;
        head->prev = mp[key];
        head = head->prev;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()){
            if (mp[key] == head){
                return mp[key]->value;
            }
            move(key);           
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()){
            mp[key]->value = value;
            if (mp[key] == head){
                return;
            }
            move(key);
        }
        else if (cap == length){
            ListNode* tmp = tail;
            tail = tail->prev;
            if (tail == NULL){
                head = NULL;
            } else{
                tail->next = NULL;
            }
            mp.erase(tmp->key);
            delete tmp;
            insert (value, key); 
        }
        else {
            insert (value, key);
            length+=1;
        }
    }
};
