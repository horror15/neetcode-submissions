class Solution {
public:
    void test(vector<int>& candidates, int target, int start, vector<int>& vec, vector<vector<int>>& out, int sum) {
        if(sum > target){
            return;
        }
        if(sum == target){
            out.push_back(vec);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]){
                continue;
            } 
            sum += candidates[i];
            vec.push_back(candidates[i]);
            test(candidates, target, i+1, vec, out, sum);
            sum -= candidates[i];
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        vector<vector<int>> out;
        sort(candidates.begin(), candidates.end());
        test(candidates, target, 0, vec, out, 0);
        return out;
    }
};
