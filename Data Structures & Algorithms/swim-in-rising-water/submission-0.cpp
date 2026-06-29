class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int en_row = grid.size()-1;
        int en_col = grid.size()-1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!pq.empty()){
            vector<int> vec = pq.top();
            pq.pop();
            int row = vec[1];
            int col = vec[2];
            int level = vec[0];
            if(row == grid.size()-1 && col == grid.size()-1) return level;
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 &&ncol<grid.size() && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    pq.push({max(grid[nrow][ncol], level), nrow, ncol});
                }

            }
        }
        return 0;
    }
};
