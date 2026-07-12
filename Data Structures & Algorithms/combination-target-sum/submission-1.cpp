class Solution {
public:
    void test(vector<int>& nums, int target, int start, int& sum, vector<vector<int>>& out, vector<int>& vec){
        if(sum>target){
            return;
        }
        if(sum == target){
            out.push_back(vec);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            sum += nums[i];
            vec.push_back(nums[i]);
            test(nums, target, i, sum, out, vec);
            sum -= nums[i];
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> vec;
        vector<vector<int>> out;
        int sum = 0;
        test(nums, target, 0, sum, out, vec);
        return out;
    }
};
