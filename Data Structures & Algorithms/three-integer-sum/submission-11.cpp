class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>out;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = 0-(nums[i]);
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                int sum = nums[j]+nums[k];
                if(sum>target){
                    k--;
                } else if(sum<target){
                    j++;
                } else{
                    out.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return out;
    }
};
