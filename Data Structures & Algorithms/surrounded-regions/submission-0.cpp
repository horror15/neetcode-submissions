class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col] == 'X' || board[row][col] == 'A'){
            return;
        }
        board[row][col] = 'A';
        dfs(board, row+1, col);
        dfs(board, row, col+1);
        dfs(board, row-1, col);
        dfs(board, row, col-1);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i=0; i<row; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][col-1] == 'O'){
                dfs(board, i, col-1);
            }
        }
        for(int i=0; i<col; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[row-1][i] == 'O'){
                dfs(board, row-1, i);
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
