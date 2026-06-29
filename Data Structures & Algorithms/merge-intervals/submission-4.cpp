class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int i=1;
        vector<vector<int>>vec;
        while(i<intervals.size()){
            if(intervals[i][1] < start){
                vec.push_back(intervals[i]);
            }
            if(intervals[i][0] <= end){
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
            }
            if(end < intervals[i][0]) {
                vec.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        vec.push_back({start, end});

        return vec;
    }
};
