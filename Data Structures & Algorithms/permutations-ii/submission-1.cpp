class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void backtrack(vector<int> &nums, vector<vector<int>> &output, int start){
        if(start == nums.size()){
            output.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=start; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                continue;
            }
            s.insert(nums[i]);
            swap(nums, i, start);
            backtrack(nums, output, start+1);
            swap(nums, i, start);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        int start = 0;
        backtrack(nums, output, start);
        return output;
    }
};