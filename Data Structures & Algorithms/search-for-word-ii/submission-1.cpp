class Solution {
    struct Node{
        Node* arr[26];
        bool terminal;
        Node(){
            for(int i=0; i<26; i++){
                arr[i] = nullptr;
            }
            terminal = false;
        }
    };
public:
    void dfs(vector<vector<char>>& board, Node* root, vector<string> &out, int row, int col, string str){
        if(root->terminal == true){
            out.push_back(str);
            root->terminal = false;
        }
        if(row<0 || col<0 || row == board.size() || col == board[0].size() || board[row][col] == '#' || root->arr[board[row][col] - 'a'] == nullptr) {
            return;
        }
        Node* next = root->arr[board[row][col] - 'a'];
        str += board[row][col];
        char ch = board[row][col];
        board[row][col] = '#';
        dfs(board, next, out, row+1, col, str);
        dfs(board, next, out, row-1, col, str);
        dfs(board, next, out, row, col+1, str);
        dfs(board, next, out, row, col-1, str);
        board[row][col] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(int i=0; i<words.size(); i++){
            Node* tmp = root; 
            for(int j=0; j<words[i].size(); j++){
                if(tmp->arr[words[i][j] - 'a'] == nullptr){
                    tmp->arr[words[i][j] - 'a'] = new Node();
                }
                tmp = tmp->arr[words[i][j] - 'a'];
            }
            tmp->terminal = true;
        }
        vector<string>out;
        string str = "";
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, root, out, i, j, str);
            }
        }
        return out;
    }
};
