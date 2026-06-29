class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> p;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vec(queries.size(), -1);
        for(int i=0; i<queries.size(); i++){
            p.push_back({queries[i], i});
        }
        sort(p.begin(), p.end());
        int i=0;
        int j=0;
        while(i<p.size()){
            while(j<intervals.size() && intervals[j][0] <= p[i].first){
                int leng = intervals[j][1] - intervals[j][0] + 1;
                pq.push({leng, intervals[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second < p[i].first){
                pq.pop();
            }
            if(!pq.empty()){
                vec[p[i].second] = pq.top().first;
            }
            i++;
        }
        return vec;
    }
};
