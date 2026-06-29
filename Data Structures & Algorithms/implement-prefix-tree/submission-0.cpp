struct Node{
    Node* arr[26];
    bool terminalNode;
    Node(){
        terminalNode = false;
        for(int i=0; i<26; i++) arr[i] = nullptr;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if (node->arr[word[i] - 'a'] == NULL){
                Node* new_node = new Node();
                node->arr[word[i] - 'a'] = new_node;
            }
            node = node->arr[word[i] - 'a'];
        }
        node->terminalNode = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->arr[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->arr[word[i] - 'a'];
        }
        if(node->terminalNode) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(node->arr[prefix[i] - 'a'] == NULL){
                return false;
            }
            node = node->arr[prefix[i] - 'a'];
        }
        return true;
    }
};
