class Solution {
public:
    bool test(vector<vector<char>>& board, string word, int i, int j, string s){
        if(word == s) return true;
        if(i<0 || j<0 || i == board.size() || j == board[0].size() || s.size() == word.size() || board[i][j] == '#'){
            return false;
        }
        s += board[i][j]; 
        char tmp = board[i][j];
        board[i][j] = '#';
        bool res =  test(board, word, i+1, j, s) || 
        test(board, word, i-1, j, s) ||
        test(board, word, i, j+1, s) ||
        test(board, word, i, j-1, s);
        board[i][j] = tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                string s= "";
                bool res = test(board, word, i, j, s);
                if(res == true){
                    return res;
                }
            }
        }
        return false;
    }
};
