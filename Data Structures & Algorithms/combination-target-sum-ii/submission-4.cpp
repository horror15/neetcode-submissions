class Solution {
public:
    void backtrack(vector<int> &candidates, vector<vector<int>> &output, vector<int> &p, int start, int target, int sum){
        if(sum == target){
            output.push_back(p);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]){
                continue;
            }
            if(sum + candidates[i]  > target){
                break;
            }
            p.push_back(candidates[i]);
            backtrack(candidates, output, p, i+1, target, sum+candidates[i]);
            p.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> p;
        sort(candidates.begin(), candidates.end());
        int start = 0;
        int sum = 0;
        backtrack(candidates, output, p, start, target, sum);
        return output;
    }
};
