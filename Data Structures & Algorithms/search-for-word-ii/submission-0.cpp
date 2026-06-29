struct Node {
    Node* arr[26];
    bool TerminalNode;
    Node(){
        for( int i=0; i<26; i++) arr[i] = nullptr;
        TerminalNode = false;
    }
};

class Solution {
public:
    Node* root;
    void backtrack(vector<vector<char>> &board, Node* node, int row, int col, string st, vector<string> &output){
        if(row < 0 || col < 0 || row > board.size()-1 || col > board[0].size()-1 || board[row][col] == '#'){
            return;
        }
        char ch = board[row][col];

        if(!node->arr[ch - 'a']) return;

        st = st+ch;
        node = node->arr[ch - 'a'];

        if(node->TerminalNode){
            output.push_back(st);
            node->TerminalNode = false;
        }
        board[row][col] = '#';
        backtrack(board, node, row+1, col, st, output);
        backtrack(board, node, row, col+1, st, output);
        backtrack(board, node, row-1, col, st, output);
        backtrack(board, node, row, col-1, st, output);
        board[row][col] = ch;
        return;
    }
    void insert(string word){
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        vector<string> output;
        for(auto word: words){
            insert(word);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                backtrack(board, root, i, j, "", output);
            }
        }
        return output;
    }
};
