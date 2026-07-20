class Solution {
public:
    bool test(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index == word.size()) return true;
        if(i<0 || j<0 || i == board.size() || j == board[0].size() || board[i][j] == '#' || word[index]!=board[i][j]){
            return false;
        }

        char tmp = board[i][j];
        board[i][j] = '#';
        bool res =  test(board, word, i+1, j, index+1) || 
        test(board, word, i-1, j, index+1) ||
        test(board, word, i, j+1, index+1) ||
        test(board, word, i, j-1, index+1);
        board[i][j] = tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                bool res = test(board, word, i, j, 0);
                if(res == true){
                    return res;
                }
            }
        }
        return false;
    }
};
