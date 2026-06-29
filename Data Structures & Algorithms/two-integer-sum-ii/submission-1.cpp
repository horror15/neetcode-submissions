class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        vector<int>out;
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum>target){
                j--;
            } else if(sum<target){
                i++;
            } else{
                out.push_back(i+1);
                out.push_back(j+1);
                break;
            }
        }
        return out;
    }
};
