class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n = nums.size();
        int target = n-1;
        bool result = false;
        for(int i=n-2; i>=0; i--){
            int jump = target-i;
            if(nums[i]>=jump){
                target = i;
                result = true;
            } else{
                result = false;
            }
        }
        return result;
    }
};
