class Solution {
public:

    void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited){

        if(visited[node] == true){
            return;
        }
        visited[node] = true;
        for(auto it: adj[node]){
            dfs(adj, it, visited);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        for(int i=0; i<visited.size(); i++){
            if(visited[i] == false){
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};
