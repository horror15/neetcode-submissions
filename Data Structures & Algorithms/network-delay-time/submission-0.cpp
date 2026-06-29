class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        int min_dist = INT_MAX;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            for(int i=0; i<adj[node].size(); i++){
                int src_node = adj[node][i].first;
                int src_dist = dist[node] + adj[node][i].second;
                if(src_dist < dist[src_node]){
                    dist[src_node] = src_dist;
                    pq.push({src_dist, src_node});
                }
            }
            pq.pop();
        }
        int max_time = INT_MIN;
        for(int i=1; i<n+1; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }   
        return max_time;
    }
};