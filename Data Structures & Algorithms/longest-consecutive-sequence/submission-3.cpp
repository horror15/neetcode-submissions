class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            int num = 0;
            int start = 0;
            if(!s.count(nums[i]-1)){
                num = nums[i];
                while(s.count(num)){
                    num++;
                    start++;
                }
                count = max(count, start);
            }
        }
        return count;
    }
};
