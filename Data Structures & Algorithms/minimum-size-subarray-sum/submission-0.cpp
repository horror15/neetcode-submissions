class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int sum=0;
        int min_len = INT_MAX;
        while(j<nums.size()){
            sum += nums[j]; 
            if(sum>=target){
                while(sum>=target && i<=j){
                    min_len = min(min_len, j-i+1);
                    sum -= nums[i];
                    i++;
                }
            }
            j++;
        }
        if(min_len == INT_MAX){
            return 0;
        }
        return min_len;
    }
};