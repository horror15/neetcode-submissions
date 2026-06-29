class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        int min_num = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max({nums[i]*dp[i-1], nums[i], nums[i]*min_num});
            min_num = min({nums[i]*dp[i-1], nums[i], nums[i]*min_num});
        }
        int max_prod = INT_MIN;
        for(int i=0; i<dp.size(); i++){
            max_prod = max(max_prod, dp[i]);
        }
        return max_prod;
    }
};
