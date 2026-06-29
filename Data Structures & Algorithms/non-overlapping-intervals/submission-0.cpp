class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int i=1;
        int count=0;
        while(i<intervals.size()){

            if(intervals[i][0] < end){
                count++;
                end = min(intervals[i][1], end);
            } else {
                end = intervals[i][1];
            }
            i++;
        }
        return count;
    }
};
