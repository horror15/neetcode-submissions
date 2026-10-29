class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_end = 0, jumps=0, farthest_index=0;
        for(int i=0; i<nums.size()-1; i++){
            farthest_index = max(farthest_index, i+nums[i]);
            if(i==curr_end){
                jumps++;
                curr_end = farthest_index;
            }
        }
        return jumps;
    }
};
