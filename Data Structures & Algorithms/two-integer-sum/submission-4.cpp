class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            if (mp.find(val) != mp.end()){
                vec.push_back(mp[val]);
                vec.push_back(i);
                return vec;
            } 
            mp[nums[i]] = i;
        }
    }
};
