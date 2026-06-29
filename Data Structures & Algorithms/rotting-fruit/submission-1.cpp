class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int count = 0;
        while(!q.empty()){
            bool rotting = false;
            int size = q.size();
            while (size > 0){
                vector<pair<int, int>> vec = {{1,0}, {0,1}, {-1,0}, {0,-1}};
                pair<int, int> p = q.front();
                q.pop();
                for (int i=0; i<vec.size(); i++){
                    int r = p.first+vec[i].first;
                    int c = p.second+vec[i].second;
                    if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        rotting = true;
                        fresh--;
                    }
                }
                size--;
            }
            if (rotting) count++;
        }
        if(fresh == 0) return count;
        return -1;
    }
};
