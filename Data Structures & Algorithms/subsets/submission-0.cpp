class Solution {
public:

    vector<vector<int>> backtrack(vector<int> nums, vector<vector<int>> &vec, vector<int> &p, int start){

        vec.push_back(p);
        for (int i= start; i < nums.size(); i++) {
            p.push_back(nums[i]);
            backtrack(nums, vec, p, i+1);
            p.pop_back();
        }
        return vec;       
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vec;
        vector<int>p;
        int start = 0;
        backtrack(nums, vec, p, start);
        return vec;
    }
};
