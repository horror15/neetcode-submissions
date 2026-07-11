class Solution {
public:
    int sum(vector<int>& nums, int i, int curr_xor, int& total){
        total += curr_xor;
        for(int j=i; j<nums.size(); j++){
            sum(nums, j+1, curr_xor^nums[j], total);
        }   
        return total;
    }
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        return sum(nums, 0, 0, total);
    }
};