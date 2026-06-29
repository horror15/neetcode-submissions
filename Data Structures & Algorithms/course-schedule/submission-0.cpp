class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int topo = 0;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            topo++;
            for(int i=0; i<adj[p].size(); i++){
                indegree[adj[p][i]]--;
                if(indegree[adj[p][i]] == 0){
                    q.push(adj[p][i]);
                }
            }
        }
        if(topo == numCourses) return true;
        return false;
    }
};
