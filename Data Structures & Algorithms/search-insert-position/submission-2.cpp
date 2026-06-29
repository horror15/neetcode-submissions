class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;

        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]>target){
                j = mid-1;
            } else if(nums[mid]<target){
                i = mid+1;
            } else{
                return mid;
            }
        }
        if(j==-1){
            return 0;
        }
        if(nums[j] > target){
            return j-1;
        } 
        return j+1;
    }
};