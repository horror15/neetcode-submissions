class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0; 
        vector<int>leftmax(height.size(), 0);
        vector<int>rightmax(height.size(), 0);
        for(int i=1; i<height.size(); i++){
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }
        for(int j=height.size()-2; j>=0; j--){
            rightmax[j] = max(rightmax[j+1], height[j+1]);
        }
        int area = 0;
        for(int i=0; i<height.size(); i++){
            int a = min(leftmax[i], rightmax[i]);
            if(height[i]<a){
                area += (a-height[i]);
            }
        }
        return area;
    }
};
