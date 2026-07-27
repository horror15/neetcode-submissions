class Solution {
public:
    bool issafe(vector<string>& queen, int row, int col, int n){
        for(int i=0; i<row; i++){
            if(queen[i][col] == 'Q') return false;
        }
        for(int i=0; i<col; i++){
            if(queen[row][i] == 'Q') return false;
        }
        int i=row-1, j=col-1;
        while(i>-1 && j>-1){
            if(queen[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i=row-1;
        j=col+1;
        while(i>-1 && j<n){
            if(queen[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void dfs(vector<vector<string>>& out, vector<string>& queen, int row, int n){
        if(row == n){
            out.push_back(queen);
        }
        for(int i=0; i<n; i++){
            if(issafe(queen, row, i, n)){
                queen[row][i] = 'Q';
                dfs(out, queen, row+1, n);
                queen[row][i] = '.';
            }
        }
    }   
    vector<vector<string>> solveNQueens(int n) {
        vector<string>queen(n, string(n, '.'));
        vector<vector<string>>out;
        dfs(out, queen, 0, n);
        return out;
    }
};
