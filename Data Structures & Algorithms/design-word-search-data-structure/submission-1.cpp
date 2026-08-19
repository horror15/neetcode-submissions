class WordDictionary {
    struct Node{
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
    WordDictionary() {
        root = new Node();
    }
    bool dfs(string word, int index, Node* root){
        if(index == word.size()){
            return root->terminal;
        }

        if(word[index] == '.'){
            for(int i=0; i<26; i++){
                if(root->arr[i] != nullptr && dfs(word, index+1, root->arr[i])){
                    return true;
                }
            }
        }else if(root->arr[word[index] - 'a'] != nullptr && dfs(word, index+1, root->arr[word[index] - 'a']) ){
            return true;
        }
        return false;
    }
    void addWord(string word) {
        Node* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(tmp->arr[word[i]-'a'] == nullptr){
                tmp->arr[word[i]-'a'] = new Node();
            }
            tmp = tmp->arr[word[i]-'a'];
        }
        tmp->terminal = true;
    }
    
    bool search(string word) {
        int index = 0;
        Node* tmp = root;
        return dfs(word, index, root);
    }
};
