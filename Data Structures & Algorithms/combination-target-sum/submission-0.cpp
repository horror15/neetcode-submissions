class Solution {
public:
    vector<vector<int>> backtrack(vector<int> nums, vector<vector<int>> &vec, vector<int> &p, int start, int target, int sum){
        if (sum == target){
            vec.push_back(p);
            return vec;
        } 
        if (sum > target){
            return vec;
        }
        for(int i=start;i<nums.size();i++){
            p.push_back(nums[i]);
            backtrack(nums, vec, p, i, target, sum+nums[i]);
            p.pop_back();
        }
        return vec;
    } 
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>vec;
        vector<int>p;
        int start = 0;
        int sum = 0;
        return backtrack(nums, vec, p, start, target, sum);
    }
};
