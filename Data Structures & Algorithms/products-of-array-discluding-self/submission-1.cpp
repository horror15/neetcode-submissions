class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>vec;
        vector<int>left(nums.size(), 1);
        vector<int>right(nums.size(), 1);
        int val = 1;
        for(int i=1; i<nums.size(); i++){
            left[i] = val*nums[i-1];
            val = left[i];
        }
        for(int i=0; i<left.size(); i++){
            cout<<left[i];
        }
        
        val = 1;
        for(int i=nums.size()-2; i>=0; i--){
            right[i] = val*nums[i+1];
            val = right[i];
        }
        for(int i=0; i<right.size(); i++){
            cout<<right[i];
        }
        for(int i=0; i<nums.size(); i++){
            vec.push_back(left[i]*right[i]);
        }
        return vec;
    }
};
