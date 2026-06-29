class Solution {
public:

    bool issafe(vector<string> &board, int row, int col){
        // look up
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }
        // look up right 
        for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        //look up left
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string> &board ,int row, int &total){
        if(row == board.size()){
            total++;
            return;
        }
        for(int i=0; i<board.size(); i++){
            board[row][i] = 'Q';
            if(issafe(board, row, i)){
                backtrack(board, row+1, total);
            }
            board[row][i] = '.';
        }
        return;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int total = 0;
        backtrack(board, 0, total);
        return total;
    }
};