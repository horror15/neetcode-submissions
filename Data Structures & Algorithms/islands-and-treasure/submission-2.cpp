class Solution {
public:


    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>> vec = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int row = p.first + vec[i].first;
                int col = p.second + vec[i].second;
                if(row<grid.size() && col<grid[0].size() && row > -1 && col > -1 && grid[row][col] == INT_MAX)     {
                    grid[row][col] = 1+grid[p.first][p.second];
                    q.push({row,col});
                }
            }

        }
    }
};
