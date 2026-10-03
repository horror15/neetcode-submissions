class Solution {
public:
    int find(int edge, vector<int>&parent){
        if(parent[edge] == edge){
            return edge;
        }
        return parent[edge] = find(parent[edge], parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int connected = n;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<edges.size(); i++){
            int u = find(edges[i][0], parent);
            int v = find(edges[i][1], parent);
            if(u!=v){
                connected--;
            }
            if(rank[u] > rank[v]){
                parent[v] = u;
            } else if (rank[u] < rank[v]){
                parent[u] = v;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }

        return connected;
    }
};
