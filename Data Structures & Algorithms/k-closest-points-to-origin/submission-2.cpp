class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>>pq;
        vector<vector<int>>out;
        for(int i=0; i<points.size(); i++){
            float dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dis = sqrt(dis);
            pq.push({dis, i});
        }
        while(k){
            pair<int, int>p=pq.top();
            out.push_back(points[p.second]);
            k--;
            pq.pop();
        }
        return out;
    }
};
