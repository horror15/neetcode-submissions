class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>vec(nums.size());
        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            vec[i] = prefix;
            prefix = prefix*nums[i];
        }
        int suffix = 1;
        for(int i=nums.size()-1; i>=0; i--){
            vec[i] *= suffix;
            suffix = suffix*nums[i];
        }
        return vec;
    }
};
