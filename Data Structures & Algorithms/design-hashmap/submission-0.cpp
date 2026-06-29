class MyHashMap {
    struct Node {
        int key;
        int val;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
        }
    };
    vector<Node*>vec;
public:
    MyHashMap() {
        vec.resize(10007, nullptr);
    }
    
    void put(int key, int value) {
        int index = key%10007;
        Node* head = vec[index];
        while(head && head->key != key) {
            head = head->next;
        }
        if(head){
            head->val = value;
            return;
        }
        Node* node = new Node(key, value);
        node->next = vec[index];
        vec[index] = node;
    }
    
    int get(int key) {
        int index = key%10007;
        Node* head = vec[index];
        while(head && head->key != key){
            head = head->next;
        }
        if(head){
            return head->val;
        }
        return -1;
        
    }
    
    void remove(int key) {
        int index = key%10007;
        Node* head = vec[index];
        Node* tmp = nullptr;
        if(!head){
            return;
        }
        if(head->key == key){
            vec[index] = nullptr;
            delete head;
            return;
        }
        while (head && head->key!=key){
            tmp = head;
            head = head->next;
        }
        if(head){
            tmp->next = head->next;
            delete head;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */