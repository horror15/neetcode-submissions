class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>vec;
        int target = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int j=i+1, k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(k<nums.size()-1 && nums[k] == nums[k+1]){
                    k--;
                    continue;
                }
                if(j>i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if(sum>target){
                    k--;
                } else if(sum<target){
                    j++;
                } else{
                    vec.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

            }
        }
        return vec;

    }
};
