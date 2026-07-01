class Solution {
public:
    int search(vector<int>& nums, int target) {
       int i=0, j=nums.size()-1;
        while(i<j){
            int mid = (i+j)/2;
            if(nums[mid] > nums[j]){
                i = mid+1;
            } else {
                j = mid;
            }
        }
        int k = i-1, l = i;
        j = nums.size()-1, i = 0;
        while(i<=k){
            int mid = (i+k)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                k = mid-1;
            } else {
                i = mid+1;
            }
        }

        while(l<=j){
            int mid = (l+j)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                j = mid-1;
            } else {
                l = mid+1;
            }
        }
        return -1;
    }
};
