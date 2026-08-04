class Solution {
public:
    void dfs(string str, int open, int close, vector<string>& out, int n){
        if(str.size() == 2*n){
            out.push_back(str);
            return;
        }
        if(open < n){
            dfs(str+"(", open+1, close, out, n);
        }
        if(close<open){
            dfs(str+")", open, close+1, out, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        int close=0, open=0;
        vector<string> out;
        string str = "";
        dfs(str, open, close, out, n);
        return out;
    }
};
