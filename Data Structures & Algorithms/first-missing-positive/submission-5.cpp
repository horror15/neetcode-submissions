class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=0){
                nums[i] = INT_MAX;
            }
        }
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(index-1 >= nums.size()){
                continue;
            }
            if(nums[index-1] < 0){
                continue;
            }  
            nums[index-1] = -nums[index-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};