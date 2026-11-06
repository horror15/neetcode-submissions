class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int>out(queries.size(),-1);
        vector<pair<int, int>>p;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

        for(int i=0; i<queries.size(); i++){
            p.push_back({queries[i], i});
        }
        sort(p.begin(), p.end());
        int i=0,j=0;
        while(i<p.size()){
            while(j<intervals.size() && p[i].first>=intervals[j][0]){
                int length = intervals[j][1] - intervals[j][0] + 1;
                pq.push({length, intervals[j][1]});
                j++;
            }
            while(!pq.empty() && p[i].first>pq.top().second){
                pq.pop();
            }
            if(!pq.empty()){
                out[p[i].second] = pq.top().first;
            }
            i++;
        }
        return out;
    }
};
