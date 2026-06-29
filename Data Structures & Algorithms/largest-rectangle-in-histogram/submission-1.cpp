class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>right(heights.size(), heights.size());
        vector<int>left(heights.size(), -1);
        stack<pair<int, int>>s;
        int area = INT_MIN;

        for(int i=0; i<heights.size(); i++){

            while(!s.empty() && s.top().first>=heights[i]){
                s.pop(); 
            }
            if(s.empty()){
                left[i] = -1;
            } else{
                left[i] = s.top().second;
            }
            s.push({heights[i], i});
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=heights.size()-1; i>=0; i--){

            while(!s.empty() && s.top().first>=heights[i]){
                s.pop(); 
            }
            if(s.empty()){
                right[i] = heights.size();
            } else{
                right[i] = s.top().second;
            }
            s.push({heights[i], i});
        }
        for(int i=0; i<heights.size(); i++){
            area = max(area, heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};
