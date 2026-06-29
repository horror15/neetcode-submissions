class MyHashSet {
    struct Node {
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
    };
    int BUCKET_SIZE = 1009;
    vector<Node*> vec;

public:
    MyHashSet() {
        vec.resize(BUCKET_SIZE, NULL);
        for(int i=0; i<vec.size(); i++){
            Node* head = new Node(-1);
            vec[i] = head;
        }
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        Node* node = new Node(key);
        Node* tmp = vec[key%1009];
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    
    void remove(int key) {
        Node* node1 = vec[key%1009];
        Node* node2 = node1->next;
        while(node2 != NULL){
            if(node2->data==key){
                Node* del = node2;
                node2 = node2->next;
                node1->next = node2;
                delete del;
                return;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    
    bool contains(int key) {
        Node* node = vec[key%1009];
        while(node!=NULL){
            if(node->data == key){
                return true;
            }
            node = node->next;
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