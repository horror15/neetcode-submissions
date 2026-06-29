class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int count = 0;
        int res;
        for(auto num:nums){
            if (count == 0){
                res = num;
            }
            if (res == num){
                count+=1;
            } else {
                count-=1;
            }
        }
        return res;
    }
};