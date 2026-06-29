class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>vec;
        int count1=0, count2=0, res1=0, res2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == res1 && count1>0){
                count1++;
            } else if (nums[i] == res2 && count2>0){
                count2++;
            } else if(count1==0){
                res1 = nums[i];
                count1++;
            } else if(count2==0){
                res2 = nums[i];
                count2++;
            } else{
                count1--;
                count2--;
            }
        }
        count1=0, count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==res1){
                count1++;
            } else if(nums[i] == res2){
                count2++;
            }
        }
        if(count1>(nums.size()/3)){
            vec.push_back(res1);
        }
        if(count2>(nums.size()/3)){
            vec.push_back(res2);
        }

        return vec;
    }
};