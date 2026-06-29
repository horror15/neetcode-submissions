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

        for(int i=start; i<nums.size(); i++){
            swap(nums, start, i);
            backtrack(nums, output, start+1);
            swap(nums, start, i);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>output;
        vector<int>p;
        int start = 0;
        backtrack(nums, output, start);
        return output;
    }
};
