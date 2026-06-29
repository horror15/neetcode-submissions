class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>> &output, vector<int> &p, int start){
        if(p.size() == k){
            output.push_back(p);
            return;
        }
        for (int i=start; i<=n; i++){
            p.push_back(i);
            backtrack(n, k, output, p, i+1);
            p.pop_back();  
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>output;
        vector<int>p;
        int start = 1;
        backtrack(n, k, output, p, start);   
        return output;
    }
};