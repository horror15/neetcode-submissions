class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=1;
        vector<int>new_interval;
        vector<vector<int>>out;
        new_interval.push_back(intervals[0][0]);
        new_interval.push_back(intervals[0][1]);
        while(i<intervals.size()){
            if(new_interval[1]<intervals[i][0]){
                out.push_back(new_interval);
                new_interval[0] = intervals[i][0];
                new_interval[1] = intervals[i][1];
            } else {
                new_interval[0] = min(new_interval[0], intervals[i][0]);
                new_interval[1] = max(new_interval[1], intervals[i][1]);
            }
            i++;
        }
        out.push_back(new_interval);
        return out;

    }
};
