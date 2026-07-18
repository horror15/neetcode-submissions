class Solution {
public:
    void test(vector<int>& nums, vector<int>& vec, vector<vector<int>> &out, vector<bool>& visited, int start){
        out.push_back(vec);

        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            if(visited[i]==true) continue;
            visited[i] = true;
            vec.push_back(nums[i]);
            test(nums, vec, out, visited, i+1);
            visited[i] = false;
            vec.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        vector<int> vec;
        vector<bool> visited(nums.size(), false);
        test(nums, vec, out, visited, 0);
        return out;
    }
};
