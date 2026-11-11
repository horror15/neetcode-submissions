class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int>r[9];
        unordered_set<int>c[9];
        unordered_set<int>s[9];
        for(int row=0; row<9; row++){
            for(int col=0;  col<9; col++){
                if(board[row][col] == '.'){
                    continue;
                } else {
                    if(c[col].count(board[row][col]) || r[row].count(board[row][col]) || s[(row/3)*3 + (col/3)].count(board[row][col])){
                        return false;
                    } else{
                        c[col].insert(board[row][col]);
                        r[row].insert(board[row][col]);
                        s[(row/3)*3 + (col/3)].insert(board[row][col]);
                    }
                }
            }
        }
        return true;
    }
};
