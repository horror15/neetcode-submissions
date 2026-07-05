class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>& smaller = (nums1.size() < nums2.size()) ? nums1 : nums2;
        const vector<int>& larger  = (nums1.size() < nums2.size()) ? nums2 : nums1;
        double median = 0;
        int total = nums1.size() + nums2.size();  
        int left = 0, right = smaller.size();
        while(left<=right){
            int partitionX = (left+right)/2;
            int partitionY = (total)/2 - partitionX;
            int maxleftX =  ((partitionX-1) >= 0) ? smaller[partitionX-1]:INT_MIN;
            int minrightX = (partitionX < smaller.size()) ? smaller[partitionX] : INT_MAX;
            int maxleftY =  ((partitionY-1) >= 0) ? larger[partitionY-1]:INT_MIN;
            int minrightY = (partitionY < larger.size()) ? larger[partitionY] : INT_MAX;
            if(maxleftX <= minrightY && maxleftY <= minrightX){
                if(total%2 == 0){
                    median = (max(maxleftX, maxleftY) + min(minrightX, minrightY))/2.0;
                } else {
                    median = min(minrightX, minrightY);
                }
                break;
            } else if(maxleftX > minrightY){
                right = partitionX-1;
            } else {
                left = partitionX+1;
            }
        }
        return median;
    }
};
