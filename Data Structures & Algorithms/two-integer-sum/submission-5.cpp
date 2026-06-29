class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>vec;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) == mp.end()){
                mp[nums[i]] = i;
            } else {
                vec.push_back(mp[target-nums[i]]);
                vec.push_back(i);
                break;
            }
        }
        return vec;
    }
};
