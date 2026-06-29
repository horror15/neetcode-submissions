class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>out;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<nums.size(); j++){
                int left = j+1;
                int right = nums.size()-1;
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                while(left<right){
                    long long sum = (long long) nums[i]+nums[j]+nums[left]+nums[right];
                    if(left>j+1 && nums[left]==nums[left-1]){
                        left++;
                        continue;
                    }
                    if(right<nums.size()-1 && nums[right] == nums[right+1]){
                        right--;
                        continue;
                    }
                    if(sum>target){
                        right--;
                    } else if(sum<target){
                        left++;
                    } else {
                        out.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }

                }
            }
        }
        return out;
    }
};