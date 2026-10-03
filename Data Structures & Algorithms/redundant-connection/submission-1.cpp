class Solution {
public:
    int find(int u, vector<int> &parent){
        if(parent[u] == u){
            return parent[u];
        }
        return parent[u] = find(parent[u], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1, 0);
        vector<vector<int>>result;
        for(int i=1; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<edges.size(); i++){
            int u = find(edges[i][0], parent);
            int v = find(edges[i][1], parent);
            if(u==v) {
                result.push_back({edges[i][0],edges[i][1]});
            }
            if(rank[u] > rank[v]){
                parent[v] = u; 
            } else if(rank[u] < rank[v]){
                parent[u] = v;
            } else {
                parent[u] = v;
                rank[v]++;
            }
        }
        return result[0];
    }
};
