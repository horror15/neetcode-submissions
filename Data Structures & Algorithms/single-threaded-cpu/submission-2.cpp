class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>sorted;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for (int i=0; i<tasks.size();i++){
            sorted.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sorted.begin(), sorted.end());
        vector<int>out;
        int time = sorted[0][0];
        int index = 0;
        while(index < sorted.size() || !pq.empty()){
            if (pq.empty() && time < sorted[index][0]){
                time = sorted[index][0];
            }
            else if(index<sorted.size() && time >= sorted[index][0]) {
                pq.push({sorted[index][1], sorted[index][2]});
                index++;
            } else {
                vector<int> top = pq.top();
                out.push_back(top[1]);
                time += top[0];
                pq.pop();
            } 
        }
        return out;
        
    }
};