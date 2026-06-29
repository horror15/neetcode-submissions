class Solution {
public:
    void backtrack(vector<vector<int>>& grid, int row, int col, int &area){
        if(row<0 || col<0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0){
            return;
        }   
        grid[row][col] = 0;
        area++;
        backtrack(grid, row+1, col, area);
        backtrack(grid, row, col+1, area);
        backtrack(grid, row-1, col, area);
        backtrack(grid, row, col-1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    backtrack(grid, i, j, area);
                    max_area = max(area, max_area);
                    area = 0;
                }
            }
        }
        return max_area;
    }
};
