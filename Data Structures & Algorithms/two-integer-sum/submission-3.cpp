class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            if (mp.find(val) != mp.end() && mp[val]!=i){
                vec.push_back(i);
                vec.push_back(mp[val]);
                break;
            }
        }
        return vec;
    }
};
