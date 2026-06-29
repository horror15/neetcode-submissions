class Solution {
public:
    bool safe(vector<string> &s, int n, int c, int r) {
        // check for the up n=4
        for(int i=0; i<r; i++){
            if(s[i][c] == 'Q') return false;
        }
        // check for up-right
        for(int i = r-1, j = c+1; i > -1 && j < n; i--, j++){
            if(s[i][j] == 'Q') return false;
        }
        // check for up-left
        for(int i = r-1, j = c-1; i>-1 && j>-1; i--, j--){
            if(s[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &result, vector<string> &s, int n, int r){
        if(r == n){
            result.push_back(s);
            return;
        }

        for(int i=0 ; i<n; i++){
            s[r][i] = 'Q';
            if (safe(s, n, i, r)) {
                backtrack(result, s, n, r+1);
            }
            s[r][i] = '.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(result, board, n, 0);
        return result;
    }
};
