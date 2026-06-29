class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        int n = nums.size()-1;
        if(nums.size()==1) return true;
        for(int i=0; i<nums.size(); i++){
            if(far == i && nums[i] == 0){
                return false;
            }
            if (far >= n || i+nums[i] >=n) return true;
            far = max(far, i+nums[i]);
        }
        return true;
    }
};
