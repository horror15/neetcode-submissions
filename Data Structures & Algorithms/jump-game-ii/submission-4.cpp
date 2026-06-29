class Solution {
public:
    int jump(vector<int>& nums) {
        int far = 0;
        int count = 0;
        int curr_end = 0;
        int n = nums.size()-1;
        if(nums.size() == 1) return 0;
        for(int i=0; i<nums.size(); i++){
            far = max(far, i+nums[i]);
            if(i==curr_end){
                count++;
                curr_end = far;
            }
            if(far >= n){
                if(curr_end < far){
                    count++;
                }
                return count;
            }
        }
        return count;
    }
};
