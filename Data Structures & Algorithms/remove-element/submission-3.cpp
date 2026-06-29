class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j] == val){
                j++;
            } else {
                if(i!=j){
                    int k = nums[i];
                    nums[i] = nums[j];
                    nums[j] = k; 
                }
                i++;
                j++;
            }
        }
        return i;
    }
};