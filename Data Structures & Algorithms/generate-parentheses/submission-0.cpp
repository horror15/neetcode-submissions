class Solution {
public:
    void backtrack(vector<string> &output, string s, int n, int open, int close){
        if(s.size() == 2*n){
            output.push_back(s);
            return;
        }
        if(open > close){
            backtrack(output, s + ")", n, open, close+1);
        }
        if (open < n) {
            backtrack(output, s +"(", n, open+1, close);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>output;
        string s = "";
        int open=0;
        int close=0;
        backtrack(output, s, n, open, close);
        return output;
    }
};
