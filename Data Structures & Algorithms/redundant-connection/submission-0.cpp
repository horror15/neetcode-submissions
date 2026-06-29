class Solution {
public:

    int findparent(int node, vector<int> &parent){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>rank(n+1, 0);
        vector<int>parent(n+1, 0);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int up_u = findparent(u, parent);
            int up_v = findparent(v, parent);
            if(up_v == up_u) return {u, v};
            if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            } else if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            } else{
                parent[up_u] = up_v;
                rank[up_v]++;
            }
        }
    }
};
