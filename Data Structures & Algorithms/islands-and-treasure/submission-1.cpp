class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            vector<pair<int, int>> vec = {{1,0}, {0,1}, {-1,0}, {0,-1}};
            pair<int, int>p = q.front();
            q.pop();
            for(auto k : vec){
                int row = p.first + k.first;
                int col = p.second + k.second;
                if(row >=0 && row < grid.size() && col>=0 && col < grid[0].size() && grid[row][col] == 2147483647){
                    grid[row][col] = grid[p.first][p.second] + 1;
                    q.push({row, col});
                }
            }
        }
    }
};
