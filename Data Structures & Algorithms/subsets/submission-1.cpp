class Solution {
public:
    void test(vector<int>& nums, vector<int>& vec, int start, vector<vector<int>>& out){
        out.push_back(vec);
        for(int i=start; i<nums.size(); i++){
            vec.push_back(nums[i]);
            test(nums, vec, i+1, out);
            vec.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> vec;
        test(nums, vec, 0, out);
        return out;
    }
};
