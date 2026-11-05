class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=1, count=0;
        int prev_end = intervals[0][1];
        while(i<intervals.size()){
            if(prev_end<=intervals[i][0]){
                prev_end = intervals[i][1];
            } else {
                count++;
                prev_end = min(prev_end, intervals[i][1]);
            }
            i++;
        }
        return count;
    }
};
