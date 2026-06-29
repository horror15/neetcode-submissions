class MyHashMap {
public:
    struct Node{
        int key;
        int value;
        Node* next;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = NULL;
        }
    };
    vector<Node*> vec;
    int BUTCKET_SIZE = 10009;
    MyHashMap() {
        vec.resize(BUTCKET_SIZE, NULL);
        for(int i=0; i<vec.size(); i++){
            Node* node = new Node(-1,-1);
            vec[i] = node;
        }
    }
    
    void put(int key, int value) {
        int index = key%BUTCKET_SIZE;
        Node* node = vec[index];
        while(node->next!=NULL){
            if(node->next->key == key){
                node->next->value = value;
                return;
            }
            node = node->next;
        }
        Node* new_node = new Node(key, value);
        node->next = new_node;
    }
    
    int get(int key) {
        int index = key%BUTCKET_SIZE;
        Node* node1 = vec[index]->next;
        while(node1!=NULL){
            if(node1->key==key) return node1->value;
            node1 = node1->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key%BUTCKET_SIZE;
        Node* node1 = vec[index];
        Node* node2 = node1->next;
        while(node2!=NULL){
            if(node2->key==key){
                Node* tmp = node2;
                node2 = node2->next;
                delete tmp;
                node1->next = node2;
                return;
            }
            node1 = node1->next;
            node2 = node2->next;
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