class Solution {
public:
    bool backtrack(vector<int> &nums, vector<int> &visited, int sub_sum, int start, int current, int k){
        if(k==1) return true;
        if(current == sub_sum){
            return backtrack(nums, visited, sub_sum, 0, 0, k-1);
        }
        for(int i=start; i<nums.size(); i++){
            if(visited[i] || current+nums[i] > sub_sum){
                continue;
            }
            visited[i] = true;
            if (backtrack(nums, visited, sub_sum, i+1, current+nums[i], k)) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        vector<int> visited(nums.size(), false);
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%k !=0){
            return false;
        }
        int sub_sum = sum/k;
        int current = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        return backtrack(nums, visited, sub_sum, 0, current, k);
    }
};