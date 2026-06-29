class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int>dist(n, INT_MAX);
        for(int i=0; i<flights.size(); i++){
            int src = flights[i][0];
            int cost = flights[i][2];
            int dst = flights[i][1];
            adj[src].push_back({cost, dst});
        }

        queue<vector<int>> q;
        q.push({0, 0, src}); // stops, cost, node
        dist[src] = 0;
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            int stops = vec[0];
            int node = vec[2];
            int cost = vec[1];
            //if(stops == k+1 && node == dst) return dist[dst]; 
            if(stops == k+1) continue;
            for(auto it: adj[node]){
                int total = cost + it.first; // total is the cost to reach it.second(next node)
                if(total < dist[it.second]){
                    dist[it.second] = total;
                    q.push({stops+1, total, it.second});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];

    }
};
