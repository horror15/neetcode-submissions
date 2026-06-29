class MyHashSet {
    struct Node {
        int val;
        Node* next;
        Node(int v){
            val = v;
            next = nullptr; 
        }

    };
    vector<Node*> vec;

public:
    MyHashSet() {
        vec.resize(10007, nullptr);
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        int index = key%10007;
        Node* node = new Node(key);
        Node* head = vec[index];
        node->next = head;
        vec[index] = node;
    }
    
    void remove(int key) {
        int index = key%10007;
        Node* head = vec[index];
        Node* tmp = nullptr;
        if(!head){
            return;
        }
        if(head->val == key){
            vec[index] = head->next;
            delete head;
            return;
        }
        while(head && head->val != key){
            tmp = head;
            head = head->next;
        }
        if (head){
            tmp->next = head->next;
        }
        delete head;
    }
    
    bool contains(int key) {
        int index = key%10007;
        Node* head = vec[index];
        if(!head){
            return false;
        }
        while(head && head->val!=key){
            head = head->next;
        }
        if(head){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */