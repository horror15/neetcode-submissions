class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int i=0;
        while(i<nums.size()){
            if(mp.count(nums[i])==0){
                mp[nums[i]] = i;
            } else{
                if(abs(i-mp[nums[i]])<=k){
                    return true;
                } else{
                    mp[nums[i]] = i;
                }
            }
            i++;
        }
        return false;
    }
};