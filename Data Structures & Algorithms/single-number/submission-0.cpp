class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int output = 0;
        for(auto x: nums){
            output ^= x; 
        }
        return output;
    }
};
