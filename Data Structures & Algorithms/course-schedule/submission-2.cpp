class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>deg(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            deg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        int count = 0;
        for(int i=0; i<numCourses; i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int course = q.front();
            count++;
            for(int i=0; i<adj[course].size(); i++){
                deg[adj[course][i]]--;
                if(deg[adj[course][i]] == 0){
                    q.push(adj[course][i]);
                }
            }
            q.pop();
        }
        if(count == numCourses) return true;
        return false;
    }
};
