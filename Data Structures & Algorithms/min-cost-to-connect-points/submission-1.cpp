class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        vector<int> visited(points.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                int w = abs(a) + abs(b);
                adj[i].push_back({w, j});
                adj[j].push_back({w, i});
            }
        }
        cout<<"hello";
        int sum = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int wg = pq.top().first;
            cout<<"hello";
            pq.pop();
            if(visited[node] != 0) continue;
            visited[node] = 1;
            sum += wg;
            for(int i=0; i<adj[node].size(); i++){
                    int next_node = adj[node][i].second;
                    int weight = adj[node][i].first;
                    pq.push({weight, next_node});
            }
        }
        return sum;
    }
};
