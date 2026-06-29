class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int count = INT_MIN;
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int sum = 1;
            if(s.count(num-1)==0){
                while(s.count(num+1)){
                    num++;
                    sum++;
                }
            }
            count = max(count, sum);
        }
        return count;
    }
};
