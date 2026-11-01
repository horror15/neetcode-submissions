class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>vec;
        int i=0;
        while(i<intervals.size()){
            if(newInterval[0]>intervals[i][1]){
                vec.push_back(intervals[i]);
            } else {
                break;
            }
            i++;
        } 
        while(i<intervals.size()){
            if(newInterval[1]>=intervals[i][0]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else {
                break;
            }
            i++;
        }
        vec.push_back(newInterval);
        while(i<intervals.size()){
            vec.push_back(intervals[i]); 
           i++;
        }
        return vec;

    }
};
