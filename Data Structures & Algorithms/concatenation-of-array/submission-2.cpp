class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = 2*nums.size();
        vector<int> vec(n, 0);
        for(int i=0; i<n; i++){
            vec[i] = nums[i%(nums.size())];
        }
        return vec;
    }
};