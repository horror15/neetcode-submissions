class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int val = abs(nums[i]) - 1;
            if(nums[val]<0){
                return abs(nums[i]);
            } else {
                nums[val] = -nums[val];
            }
        }
        return 0;
    }
};
