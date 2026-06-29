class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=1, area=0;
        int max_index=-1;
        int max_height=INT_MIN;
        for(int i=0; i<height.size(); i++){
            if(height[i]>max_height){
                max_height=height[i];
                max_index = i;
            }
        }
        while(j<=max_index){
            if(height[i]>height[j]){
                j++;
            } else {
                int left = height[i];
                int k=i+1;
                while(k<j){
                    area += (left*1 - height[k]*1);
                    k++;
                }
                i=j;
                j++;
            }
        }
        i=height.size()-1;
        j=i-1;
        while(j>=max_index){
            if(height[j]<height[i]){
                j--;
            } else {
                int right = height[i];
                int k = i-1;
                while(k>j){
                    area += (right*1 - height[k]*1);
                    k--;
                }
                i=j;
                j--;
            }
        }
        return area;
    }
};
