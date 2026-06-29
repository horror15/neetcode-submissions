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
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        if(edges.size() != n-1) return false;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj, 0, visited);
        for(auto it: visited){
            if(it == false){
                return false;
            }
        }
        return true;
    }
};
