class Solution {
public:
    void test(vector<int>& nums, vector<int>& vec, vector<vector<int>> &out, vector<bool>& visited, int start){

        if(vec.size() == nums.size()){
            out.push_back(vec);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1] && visited[i-1] ==  false) continue;
            if(visited[i] == true) continue;
            visited[i] = true;
            vec.push_back(nums[i]);
            test(nums, vec, out, visited, i);
            visited[i] = false;
            vec.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        vector<int> vec;
        vector<bool> visited(nums.size(), false);
        test(nums, vec, out, visited, 0);
        return out;
    }
};