class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum = 0, count=0;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if((sum-k) == 0){
                count+=1;
            }
            if(mp.count(sum-k)){
                count += mp[sum-k];
            } 
            if(mp.count(sum)) {
                mp[sum] += 1;
            } else {
                mp[sum] = 1;
            }
        }
        return count;
    }
};