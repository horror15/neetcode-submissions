class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = nums[0], max_sum = nums[0], min_sum = nums[0], sum2=nums[0], total_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum1+nums[i] < nums[i]){
                sum1 = nums[i];
            } else {
                sum1 += nums[i];
            }
            if(sum2+nums[i] > nums[i]){
                sum2 = nums[i];
            } else {
                sum2 += nums[i];
            }

            max_sum = max(max_sum, sum1);
            min_sum = min(min_sum, sum2);
            total_sum += nums[i];

        }
        int c = total_sum - min_sum;
        if(max_sum<0) return max_sum;
        return max(c, max_sum);
    }
};