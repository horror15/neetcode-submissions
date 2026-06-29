class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;
        for (int i=0;i<points.size();i++){
            int diff = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({diff, points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>vec;
        while(pq.size()>0){
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};
