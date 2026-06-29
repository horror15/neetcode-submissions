class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=0;
        while (j<nums.size()){
            if(nums[j] == val){
                j+=1;
            } else if(nums[i] != val && nums[j] != val){
                i+=1;
                j+=1;
            } else{
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i+=1;
                j+=1;
            }

        }
        return i;
    }
};