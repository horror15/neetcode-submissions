class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>&ocean, int prevheight){
        if(row<0 || col<0 || row>heights.size()-1 || col>heights[0].size()-1 || ocean[row][col] == true || heights[row][col] < prevheight){
            return;
        }

        ocean[row][col] = true;
        dfs(heights, row+1, col, ocean, heights[row][col]);
        dfs(heights, row, col+1, ocean, heights[row][col]);
        dfs(heights, row-1, col, ocean, heights[row][col]);
        dfs(heights, row, col-1, ocean, heights[row][col]);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>out;
        vector<vector<bool>>pacific(row, vector<bool>(col, false));
        vector<vector<bool>>atlantic(row, vector<bool>(col, false));
        for(int i=0; i<col; i++){
            dfs(heights, 0, i, pacific,-1);
            dfs(heights, row-1, i, atlantic, -1);
        }

        for(int i=0; i<row; i++){
            dfs(heights, i, 0, pacific,-1);
            dfs(heights, i, col-1, atlantic,-1);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    out.push_back({i, j});
                }
            }
        }
        return out;
    }
};
