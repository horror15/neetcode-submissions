class Solution {
public:
    int find(int u, vector<int> &parent){
        if(parent[u] == u){
            return parent[u];
        }
        return parent[u] = find(parent[u], parent);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<edges.size(); i++){
            if(n-1!=edges.size()) return false;
            int u = find(edges[i][0], parent);
            int v = find(edges[i][1], parent);
            if(u==v) return false;
            if(rank[u] > rank[v]){
                parent[v] = u; 
            } else if(rank[u] < rank[v]){
                parent[u] = v;
            } else {
                parent[u] = v;
                rank[v]++;
            }
        }
        return true;
    }
};
