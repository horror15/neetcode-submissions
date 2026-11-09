class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);
        vector<int>out;
        int prefix_prod = 1;
        for(int i=1; i<nums.size(); i++){
            prefix_prod = prefix_prod*nums[i-1];
            prefix[i] = prefix_prod;
        }
        int suffix_prod = 1;
        for(int i=nums.size()-2; i>=0; i--){
            suffix_prod = suffix_prod*nums[i+1];
            suffix[i] = suffix_prod;
        }
        for(int i=0; i<nums.size(); i++){
            out.push_back(prefix[i]*suffix[i]);
        }  
        return out;
    }
};
