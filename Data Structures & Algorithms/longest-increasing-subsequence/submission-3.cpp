class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                    cout<<dp[i];
                }
            }
        }
        int max_val = 1;
        for(int i=0; i<nums.size(); i++){
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};
