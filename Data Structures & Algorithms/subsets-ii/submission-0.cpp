class Solution {
public:
    void backtrack(vector<vector<int>> &output, vector<int>& nums, vector<int> &p, int start){

        output.push_back(p);
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i] == nums[i-1]){
                continue;
            }
            p.push_back(nums[i]);
            backtrack(output, nums, p, i+1);
            p.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int>p;
        int start = 0;
        sort(nums.begin(), nums.end());
        backtrack(output, nums, p, start);
        return output;
    }
};
