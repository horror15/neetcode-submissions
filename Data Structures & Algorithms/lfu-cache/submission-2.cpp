#include <unordered_map>
using namespace std;

struct ListNode {
    int value, key, freq;
    ListNode *next, *prev;
    ListNode(int key, int value, int freq) : key(key), value(value), freq(freq), next(nullptr), prev(nullptr) {}
};

struct FreqNode {
    ListNode* head = new ListNode(0, 0, 0);
    ListNode* tail = new ListNode(0, 0, 0);
    FreqNode() {
        head->next = tail;
        tail->prev = head;
    }
    bool isEmpty() { return head->next == tail; }
};

class LFUCache {
public:
    int min_freq = 0;
    int length = 0;
    int cap;
    unordered_map<int, ListNode*> mp;
    unordered_map<int, FreqNode*> freq_map;

    LFUCache(int capacity) : cap(capacity) {}

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(ListNode* head, ListNode* node) {
        ListNode* tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
    }

    void update_list(ListNode* node) {
        int old_f = node->freq;
        remove(node);

        // If the list we just removed from is empty and was the min_freq
        if (freq_map[old_f]->isEmpty() && old_f == min_freq) {
            min_freq++;
        }

        node->freq += 1;
        int new_f = node->freq;
        
        // Ensure the new frequency bucket exists
        if (freq_map.find(new_f) == freq_map.end()) {
            freq_map[new_f] = new FreqNode();
        }
        add(freq_map[new_f]->head, node);
    }

    int get(int key) {
        if (mp.find(key) == mp.end() || cap == 0) return -1;
        update_list(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;

        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            update_list(mp[key]);
        } else {
            if (length == cap) {
                // Evict the LRU item from the LFU list
                ListNode* to_delete = freq_map[min_freq]->tail->prev;
                mp.erase(to_delete->key);
                remove(to_delete);
                delete to_delete;
                length--;
            }

            // Create new node with frequency 1
            ListNode* new_node = new ListNode(key, value, 1);
            mp[key] = new_node;
            
            if (freq_map.find(1) == freq_map.end()) {
                freq_map[1] = new FreqNode();
            }
            
            add(freq_map[1]->head, new_node);
            min_freq = 1;
            length++;
        }
    }
};