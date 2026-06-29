class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vec;
        int i=0;
        while(i<intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                vec.push_back(intervals[i]);
            } else {
                break;
            }
            i++;
        }
        while(i<intervals.size()) {
            if(intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            } else {
                break;
            }
            i++;
        }
        vec.push_back(newInterval);
        while(i<intervals.size()) {
           vec.push_back(intervals[i]); 
           i++;
        }
        return vec;
    }
};
