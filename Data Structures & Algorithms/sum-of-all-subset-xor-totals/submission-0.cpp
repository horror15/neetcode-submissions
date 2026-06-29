class Solution {
public:
    void backtrack(vector<int>& nums, int start, int xxor, int &sum){
        sum = sum + xxor;
        for (int i=start; i<nums.size(); i++){
            backtrack(nums, i+1, xxor^nums[i], sum);
        }
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> p;
        int sum = 0;
        int xxor = 0;
        backtrack(nums, 0, xxor, sum);
        return sum;
    }
};