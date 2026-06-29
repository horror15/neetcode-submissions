class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int area = INT_MIN;
        while(i<j){
            area = max(area, (j-i)*min(heights[i], heights[j]));
            if(heights[i]>heights[j]){
                j--;
            } else{
                i++;
            }
        }
        return area;
    }
};
