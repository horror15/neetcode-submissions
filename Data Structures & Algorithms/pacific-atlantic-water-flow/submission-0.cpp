class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &ocean, int row, int col, int prevheight){
        if(row<0 || col<0 || row>heights.size()-1 || col>heights[0].size()-1 || ocean[row][col] == true || heights[row][col] < prevheight){
            return;
        }
        ocean[row][col] = true;
        dfs(heights, ocean, row+1, col, heights[row][col]);
        dfs(heights, ocean, row, col+1, heights[row][col]);
        dfs(heights, ocean, row-1, col, heights[row][col]);
        dfs(heights, ocean, row, col-1, heights[row][col]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> output;
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            dfs(heights, pacific, i, 0, -1);
            dfs(heights, atlantic, i, col-1, -1);
        }
        for(int i=0; i<col; i++){
            dfs(heights, pacific, 0, i, -1);
            dfs(heights, atlantic, row-1, i, -1);
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    output.push_back({i, j});
                }
            }
        }
        return output;
    }
};
