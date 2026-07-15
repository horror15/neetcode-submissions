class Solution {
public:
    void test(int n, int k, vector<vector<int>> &out, vector<int> &vec, int start){
        if(vec.size()==k){
            out.push_back(vec);
            return;
        }
        for(int i=start; i<=n; i++){
            vec.push_back(i);
            test(n, k, out, vec, i+1);
            vec.pop_back();
        }   
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> vec;
        test(n, k, out, vec, 1);
        return out;
    }
};