class Solution {
public:
    int helper(vector<int>& nums){
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.size()-1, 0);
        vector<int> nums2(nums.size()-1, 0);
        for(int i=0; i<nums.size()-1; i++){
            nums1[i] = nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            nums2[i] = nums[i+1];
        }     

        int val1 = helper(nums1);
        int val2 = helper(nums2); 
        return max(val1, val2);
    }
};
