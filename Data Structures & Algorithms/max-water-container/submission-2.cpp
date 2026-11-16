class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1, area = 0;
        while(i<j){
            int a = min(heights[i], heights[j])*(j-i);
            area = max(area, a);
            if(heights[i]>heights[j]){
                j--;
            } else if(heights[i]<heights[j]){
                i++;
            } else {
                i++;
                j--;
            }
        }
        return area;
    }
};
