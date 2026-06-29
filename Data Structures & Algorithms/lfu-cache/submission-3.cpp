struct ListNode {
    int value;
    int key;
    int freq;
    ListNode* next;
    ListNode* prev;
    ListNode (int key, int value, int freq) : key(key), value(value), freq(freq), next(nullptr), prev(nullptr) {}
};

struct FreqNode {
    ListNode* head = new ListNode(0,0,1);
    ListNode* tail = new ListNode(0,0,1);
    FreqNode (){
        head->next = tail;
        tail->prev = head;        
    }
    bool isEmpty(){
        if (head->next == tail){
            return true;
        }
        return false;
    }
};

class LFUCache {
public:
    int min_freq = 0;
    unordered_map<int, ListNode*>mp;
    unordered_map<int, FreqNode*>freq;
    int length = 0;
    int cap;

    LFUCache(int capacity) {
        cap = capacity;
    }
    void remove(ListNode* node){
        ListNode* tmp1 = node->next;
        ListNode* tmp2 = node->prev;
        tmp1->prev = tmp2;
        tmp2->next = tmp1;

    }

    void add(ListNode* head, ListNode* node){
        ListNode* tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
    }

    void update_list(ListNode* node)
    {
            int old_freq = node->freq;
            node->freq += 1;
            if (freq.find(node->freq)!=freq.end()){
                add(freq[node->freq]->head, node);
            } else {
                FreqNode* new_node = new FreqNode();
                freq[node->freq] = new_node;
                add(new_node->head, node);
            }
            if (freq[old_freq]->isEmpty() and old_freq == min_freq){
                min_freq +=1;
            }
    }
    int get(int key) {
        if (mp.find(key)!=mp.end()){
            remove(mp[key]);
            update_list(mp[key]);
            return mp[key]->value;            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            mp[key]->value = value;
            remove(mp[key]);
            update_list(mp[key]);
        } else {
            if (cap == length){
                ListNode* node = freq[min_freq]->tail;
                node = node->prev;
                remove(node);
                mp.erase(node->key);
                length-=1;
                delete node;                
            }
            ListNode* new_node = new ListNode(key, value, 1);
            mp[key] = new_node;
            if (freq.find(new_node->freq)!=freq.end()){
                add(freq[new_node->freq]->head, mp[key]);
            } else {
                FreqNode* node = new FreqNode();
                freq[mp[key]->freq] = node;
                add(node->head, new_node);
            }
            min_freq = 1;
            length +=1;         
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */