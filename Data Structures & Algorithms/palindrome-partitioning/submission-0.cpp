class Solution {
public:
    bool palindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;

    }
    void backtrack(vector<vector<string>> &output, string s, vector<string> &p, int start){
        if(start == s.size()) {
            output.push_back(p);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string st = s.substr(start, i-start+1);
            if (palindrome(st)) { 
                p.push_back(st);
                backtrack(output, s, p, i+1);
                p.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> p;
        vector<vector<string>> output;
        int start = 0;
        backtrack(output, s, p, start);
        return output;
    }
};
