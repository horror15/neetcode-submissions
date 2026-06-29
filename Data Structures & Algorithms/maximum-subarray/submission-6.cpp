class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int prev = nums[0];
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            curr += nums[i];
            if(curr>=prev){
                if(nums[i] > curr){
                    curr = nums[i];
                }

            } else {
                if(curr < 0){
                    curr = nums[i];
                }
            }
            prev = curr;
            cout<<curr;
            sum = max(sum, curr);
        }
        return sum;
    }
};
