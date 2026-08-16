class PrefixTree {
    struct Node {
        Node* arr[26];
        bool terminal;
        Node(){ 
            terminal = false;
            for(int i=0; i<26; i++){
                arr[i] = nullptr;
            }
        }
    };
public:
    Node* root;
    PrefixTree() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->arr[word[i]-'a'] == nullptr){
                node->arr[word[i]-'a'] = new Node();
            }
            node = node->arr[word[i]-'a'];
        }
        node->terminal = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->arr[word[i]-'a'] == nullptr){
                return false;
            }
            node = node->arr[word[i]-'a'];
        }
        if(node->terminal){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(node->arr[prefix[i]-'a'] == nullptr){
                return false;
            }
            node = node->arr[prefix[i]-'a'];
        }
        return true;
    }
};
