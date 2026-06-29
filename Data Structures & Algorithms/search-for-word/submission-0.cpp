class Solution {
public:

    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int index){
        if (index == word.size()){
            return true;
        }
        if(i<0 || j <0 || i == board.size() || j == board[0].size() || board[i][j] != word[index]){
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        bool found = backtrack(board, word, i+1, j, index+1)||
                    backtrack(board, word, i-1, j, index+1)||
                    backtrack(board, word, i, j+1, index+1)||
                    backtrack(board, word, i, j-1, index+1);
        board[i][j] = tmp;
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0; j<board[0].size(); j++){
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
