class Solution {
public:

    bool dfs(vector<int>& nums, vector<int>& ss, int index, int target){
        if(index ==  nums.size()){
            return true;
        }
        for(int i=0; i<ss.size(); i++){
            if(ss[i] + nums[index] <= target){
                ss[i] += nums[index];
                if(dfs(nums, ss, index+1, target)) return true;
                ss[i] -= nums[index];
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%k!=0) return false;
        int target = sum/k;
        vector<int>ss(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, ss, 0, target);
    }
};