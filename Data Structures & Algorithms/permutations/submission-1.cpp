class Solution {
public:
    void test(vector<int>& nums, vector<int>& vec, vector<vector<int>> &out, vector<bool>& visited){
        if(nums.size() == vec.size()){
            out.push_back(vec);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(visited[i]==true) continue;
            visited[i] = true;
            vec.push_back(nums[i]);
            test(nums, vec, out, visited);
            visited[i] = false;
            vec.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> vec;
        vector<bool> visited(nums.size(), false);
        test(nums, vec, out, visited);
        return out;
    }
};
