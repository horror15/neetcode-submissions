struct Node {
    Node* arr[26];
    bool TerminalNode;
    Node(){
        for( int i=0; i<26; i++) arr[i] = nullptr;
        TerminalNode = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    bool backtrack(string &word, int index, Node* node){
        if(index == word.size()) {
            return node->TerminalNode;
        }

        if(word[index] == '.'){
            for(int i=0; i<26; i++){
                if(node->arr[i] != nullptr && backtrack(word, index+1, node->arr[i])){
                   return true;
                }
            }
        } else {
            if (node->arr[word[index]-'a'] != nullptr && backtrack(word, index+1, node->arr[word[index]-'a'])){
                return true;
            }
        }
        return false;
    }
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->arr[word[i]- 'a'] == nullptr){
                Node* new_node = new Node();
                node->arr[word[i]-'a'] = new_node;
            }
            node = node->arr[word[i]-'a'];
        }
        node->TerminalNode = true;
    }
    
    bool search(string word) {
        Node* node = root;
        return backtrack(word, 0, node);
    }
};
